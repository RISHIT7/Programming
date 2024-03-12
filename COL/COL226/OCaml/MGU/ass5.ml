open List

type symbol = string * int;;
type signature = symbol list;;
type variable = V of string;;
type tree = V of string | C of { node: symbol; children: tree list};;

exception NOT_UNIFIABLE

let remove_dups list = 
  let rec remove_help list past = match list with 
  | [] -> past
  | x::list -> if List.mem x past then remove_help list past
               else remove_help list (x::past)
  in
  remove_help list []
;;


(* ------------------------------------------- check signature --------------------------------------------------*)

let check_sig sign = 
      let rec check_sig_helper past_sym sign = match sign with
    | [] -> true
    | (symbol, arity)::sign -> if List.mem symbol past_sym then false
                  else if arity < 0 then false
                  else
                    check_sig_helper (symbol::past_sym) sign
               in
  check_sig_helper [] sign ;;

(* ------------------------------------------- well formed tree ---------------------------------------------------- *)

let rec wftree tree sign = if check_sig sign then
  match tree with
| V x -> List.mem (x,0) sign
| C r -> let (s, n) = r.node in
            if List.mem (s, n) sign then (List.for_all (fun child -> wftree child sign) r.children)
            else false
                         else false
;;

(* ------------------------------------------ ht size and vars ------------------------------------------------------- *)

let rec ht tree = match tree with
|  V _ -> 0
| C r -> let (s, n) = r.node in
         (if n = 0 then 0 else 1 + (fold_left max 0 (map ht r.children)))
;;

let rec size tree = match tree with
|  V _ -> 1
| C r ->  1 + (fold_left (+) 0 (map size r.children))
;;

let vars tree =
  let rec vars_help tree = match tree with
  |  V x -> [x]
  |  C r -> let (s, n) = r.node in
          (if n = 0 then [s] else [] @ (fold_left (@) [] (map vars_help r.children)))
  in
  remove_dups (vars_help tree)
;;

(* -------------------------------------------- mirror ----------------------------------------------------------------- *)

let rec mirror tree = match tree with
| V x -> V x
| C r -> C {node = r.node; children = List.rev_map mirror r.children}
;;

(* ---------------------------------------------------- substitution ---------------------------------------------------- *)

type substitution = (string * tree) list;;
type composition_subs = substitution list;;

let subst_valid sign = 
  let rec subst_valid_helper past_sym sign = match sign with
| [] -> true
| (s, _)::sign -> if List.mem s past_sym then false
                  else
                    subst_valid_helper (s::past_sym) sign
              in
subst_valid_helper [] sign ;;

(* [x, 3] [y, 3] [z, y]/ [y, 3] [x, 3] -> [x, 3] [y, 3] [z, 3]*)

let compose subset1 subset2 = 
  let rec compose_help subset1 subset2 result = match subset1 with
  | (x, y)::rest -> let help (x, y) subset2 = List.assoc_opt y subset2
    in
      compose_help rest subset2 ((help (x, y) subset2)::result)
  | [] -> []
  in 
  compose_help subset1 subset2 []
;;

(* --------------------------------------------------------------- subset func ------------------------------------------- *)

let rec subst subset1 tree = match tree with
| V x -> (
  match List.assoc_opt x subset1 with
  | Some replacement -> replacement
  | None -> V x
)
| C r -> C {node = r.node; children = map (subst subset1) r.children}
;;

(* ------------------------------------------------------------- mgu ------------------------------------------------------ *)
let rec mgu t1 t2 =
  match t1, t2 with
  | V x, V y when x = y -> []
  | C r1, C r2 when r1.node = r2.node && List.length r1.children = List.length r2.children ->
    List.fold_left2 (fun acc child1 child2 -> acc @ mgu child1 child2) [] r1.children r2.children
  | V x, t | t, V x when not (occurs_check x t) -> [(x, t)]
  | C _, V _ | V _, C _ -> raise NOT_UNIFIABLE
  | C _, C _ -> raise NOT_UNIFIABLE
and occurs_check x t =
  match t with
  | V y when x = y -> true
  | C r -> List.exists (occurs_check x) r.children
  | _ -> false
;;

(* ------------------------------------------------ print helpers -------------------------------------------------------- *)


let rec print_list list = match list with
| x::list -> x ^ print_list list
| [] -> ""

let rec print_tree tree =
  match tree with
  | V x -> Printf.printf "%s" x
  | C r ->
    Printf.printf "(%s, %d) -> [" (fst r.node) (snd r.node);
    List.iter print_tree r.children;
    Printf.printf "]\n"
;;

(* --------------------------------------------------------- test cases --------------------------------------------------------- *)
(* 
(* -------------------------------------------- Test Case 1 -----------------------------------------------*)
let tree1_1 = C { node = ("f", 2); children = [V "x"; V "y"] }
let tree1_2 = C { node = ("f", 2); children = [V "a"; V "b"] }
let uni1 = mgu tree1_1 tree1_2  (* Should unify x -> a, y -> b *)

(*-------------------------------------------- Test Case 2 -----------------------------------------------*)

let tree2_1 = C { node = ("g", 0); children = [] }
let tree2_2 = C { node = ("h", 0); children = [] }
let uni2 = mgu tree2_1 tree2_2  (* Should raise NOT_UNIFIABLE *)

(*-------------------------------------------- Test Case 3 -----------------------------------------------*)
let tree3_1 = C { node = ("f", 2); children = [V "x"; C { node = ("g", 2); children = [V "y"; V "z"] }] }
let tree3_2 = C { node = ("f", 2); children = [C { node = ("g", 2); children = [V "a"; V "b"] }; V "z"] }
let uni3 = mgu tree3_1 tree3_2  (* Should unify x -> g(a, b), y -> a, z -> b *)

(*-------------------------------------------- Test Case 4 -----------------------------------------------*)
let tree4_1 = C { node = ("f", 2); children = [V "x"; C { node = ("g", 2); children = [V "y"; V "z"] }] }
let tree4_2 = C { node = ("f", 2); children = [C { node = ("g", 2); children = [V "a"; V "b"] }; V "w"] }
let uni4 = mgu tree4_1 tree4_2  (* Should raise NOT_UNIFIABLE *)

(*-------------------------------------------- Test Case 5 -----------------------------------------------*)
let tree5_1 = C { node = ("f", 2); children = [V "x"; C { node = ("g", 2); children = [V "y"; V "z"] }] }
let tree5_2 = C { node = ("f", 2); children = [V "x"; C { node = ("g", 2); children = [V "a"; V "b"] }] }
let uni5 = mgu tree5_1 tree5_2  (* Should unify y -> a, z -> b *)

(*-------------------------------------------- Test Case 6 -----------------------------------------------*)
let tree6_1 = C { node = ("f", 2); children = [V "x"; V "y"] }
let tree6_2 = C { node = ("f", 2); children = [C { node = ("g", 0); children = [] }; C { node = ("h", 0); children = [] }] }
let uni6 = mgu tree6_1 tree6_2  (* Should unify x -> g(), y -> h() *)

(*-------------------------------------------- Test Case 7 -----------------------------------------------*)
let tree7_1 = C { node = ("f", 2); children = [V "x"; V "y"] }
let tree7_2 = C { node = ("f", 2); children = [V "y"; C { node = ("g", 1); children = [V "x"] }] }
let uni7 = mgu tree7_1 tree7_2  (* Should raise NOT_UNIFIABLE *)

(*-------------------------------------------- Test Case 8 -----------------------------------------------*)
let tree8_1 = C { node = ("f", 2); children = [C { node = ("g", 2); children = [V "x"; C { node = ("h", 0); children = [] }] }; V "y"] }
let tree8_2 = C { node = ("f", 2); children = [C { node = ("g", 2); children = [V "a"; C { node = ("h", 0); children = [] }] }; V "b"] }
let uni8 = mgu tree8_1 tree8_2  (* Should unify x -> a, y -> b *)

(*-------------------------------------------- Test Case 9 -----------------------------------------------*)
let tree9_1 = C { node = ("f", 2); children = [C { node = ("g", 2); children = [V "x"; C { node = ("h", 0); children = [] }] }; V "y"] }
let tree9_2 = C { node = ("f", 2); children = [C { node = ("g", 2); children = [V "a"; C { node = ("h", 0); children = [] }] }; V "z"] }
let uni9 = mgu tree9_1 tree9_2  (* Should raise NOT_UNIFIABLE *)


*)





(* 
let subst1 = [("x", "3"); ("y", "5"); ("y", "z")]
let subst2 = [("x", "5"); ("z", "3")]

let result = compose subst1 subst2

let signature = [("plus", 2); ("x", 0); ("y", 0); ("z", 0)]

let example_tree = C { node = ("plus", 2); children = [V "y"; C { node = ("times", 2); children = [V "y"; V "z"] }] } *)

(* let () = print_endline (string_of_bool (subst_valid (subst result example_tree))) *)

(* 
let () = print_tree example_tree;;
let () = print_tree (mirror example_tree);; *)

(* let result = wftree example_tree signature *)
(* let result = vars example_tree;; *)

(* let () = print_endline (print_list result);; *)

(* let signature1 = [("f", 2); ("g", 1); ("h", 0)];;
let signature2 = [("f", 2); ("g", 1); ("h", -1)];;
let signature3 = [("f", 2); ("g", 1); ("f", 0)];;

let () =
  if check_sig signature1 then
    print_endline "Signature 1 is valid"
  else
    print_endline "Signature 1 is not valid";

  if check_sig signature2 then
    print_endline "Signature 2 is valid"
  else
    print_endline "Signature 2 is not valid";

  if check_sig signature3 then
    print_endline "Signature 3 is valid"
  else
    print_endline "Signature 3 is not valid" *)