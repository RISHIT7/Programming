open Printf

type var = string
type symbol = string
type sig = (symbol * int) list
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
  | z::rest = (x = z) || (mem x rest)
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
  | x, [] -> x
  | [], x -> x
  | x::rest1, y::rest2 -> (x, y)::combine rest1 rest2
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