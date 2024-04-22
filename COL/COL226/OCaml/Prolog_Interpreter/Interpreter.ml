open Printf

type var = string
type symbol = string
type signature = (symbol * int) list
type term =
    V of var
  | N of int
  | Node of symbol * term list
  | Underscore
type atom = Atom of symbol * term list
type goal = Goal of atom list
type head = Head of atom
type body = Body of atom list
type clause = Fact of head | Rule of head * body
type program = clause list
type subs = (var * term) list

exception NOT_UNIFIABLE
exception NotFound
exception InvalidProgram
exception NotPossible

(* Helper Functions *)
let rec mem x y = match y with
    [] -> false
  | z::rest -> (x = z) || (mem x rest)
;;

let rec fold__left func e list = match list with
    [] -> e
  | x::rest -> fold__left func (func e x) rest
;;

let rec map func list = match list with
    [] -> []
  | x::rest -> (func x)::map func rest
;;

let rec combine l1 l2 = match l1, l2 with
    [], [] -> []
  | x::rest1, y::rest2 -> (x, y)::combine rest1 rest2
  | _, _ -> raise InvalidProgram
;;

let rec union l1 l2 = match l1 with
    [] -> l2
  | x::rest -> if (mem x l2) then union rest l2 else x::(union rest l2)
;;

let rec checkProgram (prog: program): bool = match prog with
    [] -> true
  | (Fact(Head(a)))::rest | (Rule(Head(a), _))::rest -> match a with
      Atom("_eq", _) | Atom("_not_eq", _) | Atom("_cut", _)
    | Atom(">", _)   | Atom("<", _) -> raise InvalidProgram
    | _ -> checkProgram rest
;;

(* Modifying Program *)
let rec modifyTerm (i: int) (t: term): term = match t with
    V(v) -> V((string_of_int i) ^ v)
  | Node(s, l) -> Node(s, map (modifyTerm i) l)
  | _ -> t
;;

let rec modifyAtom (i: int) (a: atom): atom = match a with
    Atom(s, l) -> Atom(s, map (modifyTerm i) l)
;;

let rec modifyClause (i: int) (cl: clause): clause = match cl with
    Fact(Head(a)) -> Fact(Head(modifyAtom i a))
  | Rule(Head(a), Body(al)) -> Rule(Head(modifyAtom i a), Body(map (modifyAtom i) al))
;;

let rec modifyInitialProg (i: int) (prog: program): program = match prog with
    [] -> []
  | cl::rest -> (modifyClause i cl)::modifyInitialProg (i+1) prog
;;

let rec modifyProg2 (Atom(s, _): atom) (prog: program): program = match prog with
    [] -> []
  | cl::rest -> match cl with Fact(Head(Atom(s', _))) | Rule(Head(Atom(s', _)), _) ->
                if s = s' then (modifyClause 0 cl)::modifyProg2 (Atom(s, [])) rest
                else cl::modifyProg2 (Atom(s, [])) rest
;;

(* Variable list *)
let rec vars_term (t: term): var list = 
  match t with
    V(v) -> [v]
  | Node(s, l) -> fold__left union [] (map vars_term l)
  | _ -> []
;;

let vars_atom (Atom(s, l): atom): var list = vars_term (Node(s, l))
;;

let rec vars_goal (Goal(g): goal): var list = fold__left union [] (map vars_atom g)
;;

let rec subst (s: subs) (t: term): term = match t with
    Node(s', l) -> Node(s', map (subst s) l)
  | N(_) -> t
  | Underscore -> t
  | V(x) -> match s with
                [] -> t
              | s'::rest -> if fst s' = x then snd s' else subst rest t
;;

let rec subst_atom (s: subs) (Atom(s', l): atom): atom = Atom(s', map (subst s) l)
;;

let rec variableInTerm (v: var) (t: term): bool = match t with
    V(x) -> x = v
  | Node(s, l) -> fold__left (||) false (map (variableInTerm v) l)
  | _ -> false
;;

let compose (s1:subs) (s2:subs): subs = 
  let f s x = (fst x, subst s (snd x)) 
in (map (f s2) s1) @ s2
;;

let rec mgu_term (t1:term) (t2:term): subs = match (t1, t2) with
    (V(x), V(y)) -> if x = y then [] else [(x, V(y))]
  | (V(x), Node(_, _)) -> if variableInTerm x t2 then raise NOT_UNIFIABLE else [(x, t2)]
  | (Node(_, _), V(y)) -> if variableInTerm y t1 then raise NOT_UNIFIABLE else [(y, t1)]
  | (N(n1), N(n2)) -> if n1 = n2 then [] else raise NOT_UNIFIABLE
  | (N(n1), V(x)) -> [(x, t1)]
  | (V(x), N(n2)) -> [(x, t2)] 
  | (Node(s1, l1), Node(s2, l2)) -> if s1 <> s2 || (List.length l1 <> List.length l2) then raise NOT_UNIFIABLE else
    let f s tt = compose s (mgu_term (subst s (fst tt)) (subst s (snd tt))) in
    fold__left f [] (combine l1 l2)
  | _ -> raise NOT_UNIFIABLE
;;

let mgu_atom (Atom(s1, l1): atom) (Atom(s2, l2): atom): subs = mgu_term (Node(s1, l1)) (Node(s2, l2))
;;

let rec print_term_list (tl:term list) = match tl with
    [] -> Printf.printf ""
  | [t] -> print_term t
  | t::tls -> (
      print_term t;
      Printf.printf ",";
      print_term_list tls;
    )

and print_list_body (t:term) = match t with
    Node("_empty_list", []) -> Printf.printf ""
  | Node("_list", [t1; Node("_empty_list", [])]) -> print_term t1
  | Node("_list", [t1; t2]) -> (
      print_term t1;
      Printf.printf ",";
      print_list_body t2;
    )
  | _ -> raise NotPossible

and print_term (t:term) = match t with
    V(v) -> Printf.printf " %s " v
  | Node("_empty_list", []) -> Printf.printf " [] "
  | Node(s, []) -> Printf.printf " %s " s
  | Node("_list", _) -> (
      Printf.printf " [";
      print_list_body t;
      Printf.printf "] ";
    )
  | Node(s, l) -> (
      Printf.printf " %s ( " s;
      print_term_list l;
      Printf.printf " ) ";
    )
  | Underscore -> Printf.printf ""  
  | N(n) -> Printf.printf " %d " n
;;

let rec getSolution (unif: subs) (vars: var list) = match vars with
    [] -> []
  | v::rest -> let rec occurs l = match l with
                [] -> raise NotFound
              | x::xrest -> if (fst x) = v then x
              else occurs xrest
            in
            try (occurs unif)::getSolution unif rest
          with NotFound-> getSolution unif rest
;;

let get1char () = let termio = Unix.tcgetattr Unix.stdin in
                    let () = Unix.tcsetattr Unix.stdin Unix.TCSADRAIN
                              { termio with Unix.c_icanon = false } in
                    let res = input_char stdin in
                    Unix.tcsetattr Unix.stdin Unix.TCSADRAIN termio;
                    res
;;

let rec printSolution (unif: subs) = match unif with
    [] -> Printf.printf "true. "
  | [(v, t)] -> (
    Printf.printf "%s =" v;
    print_term t;
    )
  | (v, t)::rest -> (
    Printf.printf "%s =" v;
    print_term t;
    Printf.printf ", ";
    printSolution rest;
    )
;;

let solve_atom_atom (a1: atom) (a2: atom) (unif: subs): subs = 
  compose unif (mgu_atom (subst_atom unif a1) (subst_atom unif a2))
;;

let solve_term_term (t1: term) (t2: term) (unif: subs): subs =
  compose unif (mgu_term (subst unif t1) (subst unif t2))
;;

let rec simplify_term (t:term): term = match t with
    N(_) -> t
  | Node("+", [t1; t2]) -> (
      match ((simplify_term t1), (simplify_term t2)) with
          (N(n1), N(n2)) -> N(n1 + n2)
        | _ -> raise NOT_UNIFIABLE
    )
  | Node("-", [t1; t2]) -> (
      match ((simplify_term t1), (simplify_term t2)) with
          (N(n1), N(n2)) -> N(n1 - n2)
        | _ -> raise NOT_UNIFIABLE
    )
  | Node("*", [t1; t2]) -> (
      match ((simplify_term t1), (simplify_term t2)) with
          (N(n1), N(n2)) -> N(n1 * n2)
        | _ -> raise NOT_UNIFIABLE
    )
  | Node("/", [t1; t2]) -> (
      match ((simplify_term t1), (simplify_term t2)) with
          (N(n1), N(n2)) -> N(n1 / n2)
        | _ -> raise NOT_UNIFIABLE
      )
  | _ -> t
;;

let eval (a:atom) (unif:subs): subs = match a with
    Atom("_eq", [t1; t2])
  | Atom("_not_eq", [t1; t2]) -> compose unif (mgu_term (simplify_term (subst unif t1)) (simplify_term (subst unif t2)))
  | Atom(">", [t1; t2]) -> (
        match (simplify_term (subst unif t1), simplify_term (subst unif t2)) with
            (N(n1), N(n2)) -> if n1 > n2 then unif else raise NOT_UNIFIABLE
          | _ -> raise NOT_UNIFIABLE
    )
  | Atom("<", [t1; t2]) -> (
      match (simplify_term (subst unif t1), simplify_term (subst unif t2)) with
          (N(n1), N(n2)) -> if n1 < n2 then unif else raise NOT_UNIFIABLE
        | _ -> raise NOT_UNIFIABLE
    )
  | _ -> unif
;;

let rec solve_goal (prog: program) (g: goal) (unif: subs) (vars: var list): (bool * subs) = 
  match g with
    Goal([]) -> (
      printSolution (getSolution unif vars);
      flush stdout;
      let c = ref (get1char ()) in
      while (!c <> '.' && !c <> ';') do
        Printf.printf "Invalid input. Please enter '.' or ';' ";
        flush stdout;
        c := get1char ()
      done;
      Printf.printf "\n";
      if !c = '.' then (true, []) else (false, [])
    )
  | Goal(a::grest) -> match a with
        Atom("_eq", _) | Atom(">", _) | Atom("<", _) -> (
          try solve_goal prog (Goal(grest)) (eval a unif) vars
          with NOT_UNIFIABLE -> (false, [])
        )
      | Atom("_not_eq", _) -> (
        try (false, eval a unif)
        with NOT_UNIFIABLE -> solve_goal prog (Goal(grest)) unif vars
      )
      | Atom("_cut", _) -> let _ = solve_goal prog (Goal(grest)) unif vars in (true, [])
      | _ -> let new_prog = modifyProg2 a prog in
             let rec iter prog' = match prog' with
                [] -> (false, [])
              | cl::prest -> match cl with
                  Fact(Head(a')) -> (
                    try 
                      let u = solve_atom_atom a a' unif in
                      match solve_goal prog (Goal(grest)) u vars with
                          (true, u') -> (true, u')
                        | _ -> iter prest
                    with NOT_UNIFIABLE -> iter prest
                  )
                | Rule(Head(a'), Body(al)) -> (
                  try 
                    let u = solve_atom_atom a a' unif in
                    match solve_goal prog (Goal(al @ grest)) u vars with
                        (true, u') -> (true, u')
                      | _ -> iter prest
                  with NOT_UNIFIABLE -> iter prest                
                )
        in iter new_prog
;;

let interpret_goal (prog: program) (g: goal) = solve_goal prog g [] (vars_goal g)
;;

