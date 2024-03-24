type myBool = T | F;;

type exp = 
  Num of int | Bl of myBool | V of string (* Values *)
| Plus of exp * exp | Times of exp * exp | Sub of exp * exp (* Arithmetics *)
| And of exp * exp | Or of exp * exp | Not of exp (* Boolean Arithmetics *)
| Eq of exp * exp | Gt of exp * exp (* Comparison Operators *)
| IfTE of exp * exp * exp | Case of exp * (exp list) (* Conditionals *)
| Pair of exp * exp | Fst of exp | Snd of exp (* Pair *)
;;

type values = N of int | B of bool | P of values * values;;

type opcode =   LDN of int | LDB of bool | LOOKUP of string
              | PLUS | TIMES | SUBTRACT
              | AND | OR | NOT | EQ | GT 
              | COND of opcode list * opcode list | CASE of (opcode list) list
              | PAIR | FST | SND
;;

let myBool2bool b = match b with 
| T -> true
| F -> false
;;

let rec compile e = match e with 
(* Values *)
| Num n  -> [LDN n] 
| Bl b -> [LDB (myBool2bool b) ]
| V x -> [LOOKUP x]
(* Arith *)
| Plus (e1, e2)  ->  (compile e1) @ (compile e2) @ [PLUS] 
| Times (e1, e2)  ->  (compile e1) @ (compile e2) @ [TIMES]  
| Sub (e1, e2)  ->  (compile e1) @ (compile e2) @ [SUBTRACT]  
(* Boolean Arith *)
| And (e1, e2)  ->  (compile e1) @ (compile e2) @ [AND] 
| Or (e1, e2)  -> (compile e1) @ (compile e2) @ [OR]  
| Not e1 -> (compile e1) @ [NOT] 
(* Comparison Ops *)
| Eq (e1, e2)  -> (compile e1) @ (compile e2) @ [EQ] 
| Gt(e1, e2)  -> (compile e1) @ (compile e2) @ [GT] 
(* Conditionals *)
| IfTE(e0, e1, e2) -> (compile e0) @ [COND(compile e1, compile e2)]
| Case(e0, le1) -> (compile e0) @ [CASE( List.map compile le1)]
(* Pairs *)
| Pair(e1, e2) -> (compile e1) @ (compile e2) @ [PAIR]
| Fst(e1) -> compile e1 @ [FST]
| Snd(e1) -> compile e1 @ [SND]
;; 

exception Stuck of ((string * values) list) * values list * opcode list;; 
exception Invalid_Var of string

let rec stkmc g s c = match s, c with 
(* Values *)
| v::_, [ ] -> v
| s, (LDN n)::c' -> stkmc g ((N n)::s) c' 
| s, (LDB b)::c' -> stkmc g ((B b)::s) c' 
| s, (LOOKUP x)::c' -> stkmc g ((List.assoc x g)::s) c'
(* Arith *)
| (N n2)::(N n1)::s', PLUS::c' -> stkmc g (N(n1+n2)::s') c' 
| (N n2)::(N n1)::s', TIMES::c' -> stkmc g (N(n1*n2)::s') c'  
| (N n2)::(N n1)::s', SUBTRACT::c' -> stkmc g (N(n1-n2)::s') c'
(* Boolean Arith *)
| (B b2)::(B b1)::s', AND::c' -> stkmc g (B(b1 && b2)::s') c' 
| (B b2)::(B b1)::s', OR::c' -> stkmc g (B(b1 || b2)::s') c' 
| (B b1)::s', NOT::c' -> stkmc g (B(not b1)::s') c' 
(* Comparison Ops *)
| (N n2)::(N n1)::s', EQ::c' -> stkmc g (B(n1 = n2)::s') c' 
| (N n2)::(N n1)::s', GT::c' -> stkmc g (B(n1 > n2)::s') c'
(* Conditionals *)
| (B true)::s', COND(c1, c2)::c' -> stkmc g s' (c1@c')
| (B false)::s', COND(c1, c2)::c' -> stkmc g s' (c2@c')
| (N n)::s', CASE(lc1)::c' -> stkmc g s' ((List.nth lc1 n)@c')
(* Pairs *)
| (a)::(b)::s', PAIR::c' -> stkmc g (P(b, a)::s') c'
| (P (a, b))::s', FST::c' -> stkmc g (a::s') c'
| (P (a, b))::s', SND::c' -> stkmc g (b::s') c'
(* Error *)
| _, _ -> raise (Stuck (g, s, c)) 
;; 


let test1a = Plus (Times (Num 3, Num 4), 
                   Times (Num 5, Num 6));; 
let test1b = Times (Sub (Num 3, Num 4), 
                    Times (Num 3, Num 4));; 
let test2 = Or (Not (Bl T), And (Bl T, Or(Bl F, Bl T)));; 
let test3 = Gt (Times (Num 5, Num 6),  
               (Times (Num 3, Num 4)));; 
let test4 = And (Eq(test1a, Num 42), Not test3);;
let test5 = Plus (Times (Plus (Num 1, V "x"), Num 4), 
                  Times (Num 5, Num 6));;

let test6 = IfTE (test3, test1a, test2);;
let test7 = IfTE (test3, test2, test1a);;
let test8 = IfTE (Not test3, test1a, test2);;
let test9 = IfTE (Not test3, test2, test1a);;

let test10 = Pair ( Pair (test1a, test1b), test1b);;
let test11 = Fst (test10);;
let test12 = Snd (test10);;

let test13a = Num 3;;
let test13b = Case (test13a, [test1a; test1b; test2; test3; test4; test5]);;
let test13c = Case (test13a, [test1a; test1b]);;

let gamma = [("x", N 2); ("y", B true); ("x", N 3)];;

let compiler = compile test5;;
let stack = stkmc gamma [] compiler;;

let rec string_of_value value = match value with
| N n -> (string_of_int n)
| B b -> (string_of_bool b)
| P (a, b) -> ("(" ^ (string_of_value a) ^ "," ^ (string_of_value b) ^ ")")
;;

let print_values value = match value with
| P (a, b) -> ("(" ^ (string_of_value a) ^ "," ^ (string_of_value b) ^ ")")
| n -> (string_of_value n)
;;

let () = print_endline (print_values stack);;