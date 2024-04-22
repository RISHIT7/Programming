type variable = string
type symbol = string
type signature = (symbol * int) list
type term = V of variable | N of int | Node of symbol * (term list) | Underscore
type atom = Atom of symbol * (term list)
type head = Head of atom
type body = Body of atom list
type clause = Fact of head | Rule of head * body
type program = clause list
type goal = Goal of atom list
type substitution = (variable * term) list

exception NOT_UNIFIABLE
exception NotFound
exception InvalidProgram
exception NotPossible

let rec exists x y = match y with
    [] -> false
  | z::ys -> (x = z) || (exists x ys)
;;

let rec foldl f e l = match l with
    [] -> e
  | x::xs -> foldl f (f e x) xs
;;

let rec map f l = match l with
    [] -> []
  | x::xs -> (f x)::map f xs
;;

let rec combine l1 l2 = match l1 with
    [] -> []
  | x::xs -> (x, (List.hd l2))::combine xs (List.tl l2)
;;

let rec union l1 l2 = match l1 with
    [] -> l2
  | x::xs -> if (exists x l2) then union xs l2
             else x::(union xs l2)
;;

let rec checkProgram (prog:program): bool = match prog with
    [] -> true
  | (Fact(Head(a)))::xs | (Rule(Head(a), _))::xs -> match a with
          Atom("_equal", _) | Atom("_not_equal", _) | Atom("_ofcourse", _)
        | Atom(">", _) | Atom("<", _)-> raise InvalidProgram
        | _ -> checkProgram xs
;;

let rec modifyTerm (i:int) (t:term): term = match t with
    V(v) -> V((string_of_int i) ^ v)
  | Node(s, l) -> Node(s, map (modifyTerm i) l)
  | _ -> t
;;

let rec modifyAtom (i:int) (a:atom): atom = match a with
  Atom(s, l) -> Atom(s, map (modifyTerm i) l)
;;

let rec modifyClause (cl:clause) (i:int): clause = match cl with
    Fact(Head(a)) -> Fact(Head(modifyAtom i a))
  | Rule(Head(a), Body(l)) -> Rule(Head(modifyAtom i a), Body(map (modifyAtom i) l))
;;

let rec modifyInitialProg (prog:program) (i:int): program = match prog with
    [] -> []
  | cl::ps -> (modifyClause cl i)::modifyInitialProg ps (i+1)
;;

let rec modifyProg2 (prog:program) (Atom(s, _): atom): program = match prog with
    [] -> []
  | cl::ps -> match cl with Fact(Head(Atom(s', _))) | Rule(Head(Atom(s', _)), _) ->
                if s = s' then (modifyClause cl 0)::modifyProg2 ps (Atom(s, []))
                else cl::modifyProg2 ps (Atom(s, []))
;;

let rec vars_term (t:term): variable list =
  match t with
      V(v) -> [v]
    | Node(s, l) -> foldl union [] (map vars_term l)
    | _ -> []
;;

let vars_atom (Atom(s, l): atom): variable list = vars_term (Node(s, l))
;;

let rec vars_goal (Goal(g): goal): variable list = foldl union [] (map vars_atom g)
;;

let rec subst (s:substitution) (t:term): term =
  match t with
      Node(s', l) -> Node(s', map (subst s) l)
    | N(_) -> t
    | Underscore -> t
    | V(x) -> match s with
                  [] -> t
                | s'::xs -> if fst s' = x then snd s' else subst xs t
;;

let rec subst_atom (s:substitution) (Atom(s', l): atom): atom = Atom(s', map (subst s) l)
;;

let rec variableInTerm (v:variable) (t:term): bool =
  match t with
      V(x) -> x = v
    | Node(s, l) -> foldl (||) false (map (variableInTerm v) l)
    | _ -> false
;;

let compose (s1:substitution) (s2:substitution): substitution =
  let f s x = (fst x, subst s (snd x)) in (map (f s2) s1) @ s2
;;

let rec mgu_term (t1:term) (t2:term): substitution =
  match (t1, t2) with
      (V(x), V(y)) -> if x = y then []
                      else [(x, V(y))]
    | (V(x), Node(_, _)) -> if variableInTerm x t2 then raise NOT_UNIFIABLE
                            else [(x, t2)]
    | (Node(_, _), V(y)) -> if variableInTerm y t1 then raise NOT_UNIFIABLE
                            else [(y, t1)]
    | (N(n1), N(n2)) -> if n1 = n2 then [] else raise NOT_UNIFIABLE
    | (N(n1), V(x)) -> [(x, t1)]
    | (V(x), N(n2)) -> [(x, t2)] 
    | (Node(s1, l1), Node(s2, l2)) ->
        if s1 <> s2 || (List.length l1 <> List.length l2) then raise NOT_UNIFIABLE
        else
          let f s tt = compose s (mgu_term (subst s (fst tt)) (subst s (snd tt))) in
          foldl f [] (combine l1 l2)
    | _ -> raise NOT_UNIFIABLE
;;

let mgu_atom (Atom(s1, l1): atom) (Atom(s2, l2): atom): substitution = mgu_term (Node(s1, l1)) (Node(s2, l2))
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
  | N(n) -> Printf.printf " %d " n
  | Underscore -> Printf.printf " _ "
;;

let rec getSolution (unif:substitution) (vars:variable list) = match vars with
    [] -> []
  | v::vs ->
      let rec occurs l = match l with
          [] -> raise NotFound
        | x::xs -> if (fst x) = v then x
                    else occurs xs
      in
      try (occurs unif)::getSolution unif vs
      with NotFound -> getSolution unif vs
;;

let get1char () =
  let termio = Unix.tcgetattr Unix.stdin in
  let () = Unix.tcsetattr Unix.stdin Unix.TCSADRAIN
          { termio with Unix.c_icanon = false } in
  let res = input_char stdin in
  Unix.tcsetattr Unix.stdin Unix.TCSADRAIN termio;
  res

let rec printSolution (unif:substitution) = match unif with
    [] -> Printf.printf "true. "
  | [(v, t)] -> (
      Printf.printf "%s =" v;
      print_term t;
    )
  | (v, t)::xs -> (
      Printf.printf "%s =" v;
      print_term t;
      Printf.printf ", ";
      printSolution xs;
    )
;;

let solve_atom_atom (a1:atom) (a2:atom) (unif:substitution): substitution =
  compose unif (mgu_atom (subst_atom unif a1) (subst_atom unif a2))
;;

let solve_term_term (t1:term) (t2:term) (unif:substitution): substitution =
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

let eval (a:atom) (unif:substitution): substitution = match a with
    Atom("_equal", [t1; t2])
  | Atom("_not_equal", [t1; t2]) -> compose unif (mgu_term (simplify_term (subst unif t1)) (simplify_term (subst unif t2)))
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

let rec solve_goal (prog:program) (g:goal) (unif:substitution) (vars:variable list): (bool * substitution) =
  match g with
      Goal([]) -> (
        printSolution (getSolution unif vars);
        flush stdout;
        let choice = ref (get1char()) in
        while(!choice <> '.' && !choice <> ';') do
          Printf.printf "\nUnknown Action: %c \nAction? " (!choice);
          flush stdout;
          choice := get1char();
        done;
        Printf.printf "\n";
        if !choice = '.' then (true, [])
        else (false, [])
      )
    | Goal(a::gs) -> match a with
          Atom("_equal", _) | Atom(">", _) | Atom("<", _) -> (
            try solve_goal prog (Goal(gs)) (eval a unif) vars
            with NOT_UNIFIABLE -> (false, [])
          )
        | Atom("_not_equal", _) -> (
            try (false, eval a unif)
            with NOT_UNIFIABLE -> solve_goal prog (Goal(gs)) unif vars
          )
        | Atom("_ofcourse", _) -> let _ = solve_goal prog (Goal(gs)) unif vars in (true, [])
        | _ ->
          let new_prog = modifyProg2 prog a in
          let rec iter prog' = match prog' with
              [] -> (false, [])
            | cl::ps -> match cl with
                Fact(Head(a')) -> (
                  try
                    let u = (solve_atom_atom a' a unif) in
                    match (solve_goal new_prog (Goal(gs)) u vars) with
                        (true, u') -> (true, u')
                      | _ -> iter ps
                  with NOT_UNIFIABLE -> iter ps
                )
              | Rule(Head(a'), Body(al)) -> (
                  try
                    let u = (solve_atom_atom a' a unif) in
                    match (solve_goal new_prog (Goal(al @ gs)) u vars) with
                        (true, u') -> (true, u')
                      | _ -> iter ps
                  with NOT_UNIFIABLE -> iter ps
                )
        in iter prog
;;

let interpret_goal (prog:program) (g:goal) = solve_goal prog g [] (vars_goal g)
;;
