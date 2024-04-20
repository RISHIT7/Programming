open Printf

type var = string
type symbol = string
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

let rec print_term (term : term) : unit = 
  match term with
  | V x -> Printf.printf "Variable: %s\n" x
  | N n -> Printf.printf "Integer: %d\n" n
  | B b -> Printf.printf "Boolean: %b\n" b
  | Underscore -> Printf.printf "Variable: _\n"
  | Node (s, terms) ->
    Printf.printf "Term: %s\n\t" s;
    print_term_list terms;
    Printf.printf "\n"
  
  and print_term_list (terms : term list) : unit = 
    match terms with
    | [] -> ()
    | [t] -> print_term t;
    | t :: rest ->
      print_term t;
      Printf.printf "";
      print_term_list rest;
;;

let rec print_atom (atom: atom) : unit = 
  match atom with
  | Atom (s, terms) -> 
    Printf.printf "Atom: %s\n\t" s;
    print_term_list terms;
    Printf.printf "\n"
;;


let print_head (head: head) : unit =
  match head with
  | Head atom -> print_atom atom
;;

let print_body (body: body) : unit =
  match body with
  | Body atoms ->
      List.iter (fun atom -> print_atom atom; Printf.printf "") atoms
;;

let print_clause (clause: clause) : unit =
  match clause with
  | Fact head ->
      Printf.printf "Fact: \n";
      print_head head
  | Rule (head, body) ->
      Printf.printf "Rule: \n";
      print_head head;
      Printf.printf "Cond\n";
      print_body body
;;

let print_program (program: program) : unit =
  List.iter (fun clause -> print_clause clause; Printf.printf "\n") program
;;

let print_goal (goal: goal) : unit =
  match goal with
  | Goal atoms ->
      List.iter (fun atom -> print_atom atom; Printf.printf "") atoms
;;

let rec print_ast ast =
  match ast with
  | [] -> Printf.printf "Empty AST\n"
  | clause :: rest ->
      print_clause clause;
      Printf.printf "\n";
      print_ast rest
;;