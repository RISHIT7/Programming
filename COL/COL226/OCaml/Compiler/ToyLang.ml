type myBool = T | F;;

type exp = Num of int | Bl of myBool | V of string
| Plus of exp * exp | Times of exp * exp | Sub of exp * exp
| And of exp * exp | Or of exp * exp | Not of exp
| Eq of exp * exp | Gt of exp * exp | IfTE of exp * exp * exp
;;

type values = N of int | B of bool;;

type opcode = LDN of int | LDB of bool | LOOKUP of string
              | PLUS | TIMES | SUBTRACT
              | AND | OR | NOT | EQ | GT 
              | COND of opcode list * opcode list;;

let myBool2bool b = match b with 
| T -> true
| F -> false
;;

let rec compile e = match e with 
| Num n  -> [ LDN n ] 
| Bl b -> [LDB (myBool2bool b) ]
| V x -> [LOOKUP x]
| Plus (e1, e2)  ->  (compile e1) @ (compile e2) @ [PLUS] 
| Times (e1, e2)  ->  (compile e1) @ (compile e2) @ [TIMES]  
| Sub (e1, e2)  ->  (compile e1) @ (compile e2) @ [SUBTRACT]  
| And (e1, e2)  ->  (compile e1) @ (compile e2) @ [AND] 
| Or (e1, e2)  -> (compile e1) @ (compile e2) @ [OR]  
| Not e1 -> (compile e1) @ [NOT] 
| Eq (e1, e2)  -> (compile e1) @ (compile e2) @ [EQ] 
| Gt(e1, e2)  -> (compile e1) @ (compile e2) @ [GT] 
| IfTE(e0, e1, e2) -> (compile e0) @ [COND(compile e1, compile e2)]
;; 

exception Stuck of (string -> values) * values list * opcode list;; 
exception Invalid_Var of string

let rec stkmc g s c = match s, c with 
| v::_, [ ] -> v
| s, (LDN n)::c' -> stkmc g ((N n)::s) c' 
| s, (LDB b)::c' -> stkmc g ((B b)::s) c' 
| s, (LOOKUP x)::c' -> stkmc g ((g x)::s) c'
| (N n2)::(N n1)::s', PLUS::c' -> stkmc g (N(n1+n2)::s') c' 
| (N n2)::(N n1)::s', TIMES::c' -> stkmc g (N(n1*n2)::s') c'  
| (N n2)::(N n1)::s', SUBTRACT::c' -> stkmc g (N(n1-n2)::s') c'
| (B b2)::(B b1)::s', AND::c' -> stkmc g (B(b1 && b2)::s') c' 
| (B b2)::(B b1)::s', OR::c' -> stkmc g (B(b1 || b2)::s') c' 
| (B b1)::s', NOT::c' -> stkmc g (B(not b1)::s') c' 
| (N n2)::(N n1)::s', EQ::c' -> stkmc g (B(n1 = n2)::s') c' 
| (N n2)::(N n1)::s', GT::c' -> stkmc g (B(n1 > n2)::s') c'
| (B true)::s', COND(c1, c2)::c' -> stkmc g s' (c1@c')
| (B false)::s', COND(c1, c2)::c' -> stkmc g s' (c2@c')
| _, _ -> raise (Stuck (g, s, c)) 
;; 

let test1a = Plus (Times (Num 3, Num 4), 
                  Times (Num 5, Num 6));; 
let test1b = Times (Sub (Num 3, Num 4), 
                  Times (Num 3, Num 4));; 
let test2 = Or (Not (Bl T),  
                And (Bl T,  
                     Or(Bl F,  
                        Bl T)));; 
let test3 = Gt (Times (Num 5, Num 6),  
               (Times (Num 3, Num 4)));; 

let test4 = And (Eq(test1a, Num 42), Not test3);;

let test5 = Plus (Times (Plus (Num 1, V "x"), Num 4), 
                  Times (Num 5, Num 6));;

let test6 = IfTE (test3, test1a, test2);;
let test7 = IfTE (test3, test2, test1a);;
let test8 = IfTE (Not test3, test1a, test2);;
let test9 = IfTE (Not test3, test2, test1a);;

let compiler = compile test1b;;

let [@warning "-8"]gamma v = match v with
| "x" -> N 2
| _ -> raise (Invalid_Var v)
;;

let stack = stkmc gamma [] compiler;;

let print_values value = match value with
| N n -> print_endline (string_of_int n)
| B b -> print_endline (string_of_bool b)
;;

let () = print_values stack;;