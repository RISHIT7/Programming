open Printf

type var = string
type symbol = string
type signature = (symbol * int) list
type term =
    V of var
  | N of int
  | B of bool
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

let interpret_goal (prog: program) (g: goal) = solve_goal prog g [] (vars_goal g)
;;

