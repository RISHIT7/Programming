type myBool = T | F;;

type exp = 
            Num of int | Bl of myBool | V of string (* Values *)
          | Plus of exp * exp | Times of exp * exp | Sub of exp * exp | Div of exp * exp | Raise of exp * exp | Mod of exp * exp (* Arithmetics *)
          | And of exp * exp | Or of exp * exp | Not of exp (* Boolean Arithmetics *)
          | Eq of exp * exp | Gt of exp * exp (* Comparison Operators *)
          | IfTE of exp * exp * exp | Case of exp * (exp list) (* Conditionals *)
          | Pair of exp * exp | Fst of exp | Snd of exp (* Pair *)
          | Abs of string * exp | App of exp * exp (* Abstractions *)
;;

type opcode =   
            LDN of int | LDB of bool | LOOKUP of string
          | PLUS | TIMES | SUBTRACT
          | AND | OR | NOT | EQ | GT 
          | COND of opcode list * opcode list | CASE of (opcode list) list
          | PAIR | FST | SND
          | APP | MKCLOS of string * opcode list | RET
;;

let myBool2bool b = match b with 
| T -> true
| F -> false
;;

let bool2myBool b = match b with 
| true -> T
| false -> F
;;

type codes = opcode list;;
type environment =  (string * answer) list
and answer = 
  | N of int
  | B of bool
  | P of answer * answer
  | VCLs of environment * string * codes
;;

type closure = CLtype of exp*environmentCLOS
and environmentCLOS = (exp*closure) list;;
type stackCLOS = closure list;;

type stack = answer list;;
type dump = (stack * environment * codes) list;;

exception Stuck of stack*environment*codes*dump;; 
exception InvalidVar;;
exception InvalidOperation;;
exception InvalidBigStepAnswerClosure;;
exception ReturnEmpty;;

let rec lookup (e, env) = match (e, env) with
	| (e, (e1,cl)::c') -> if e1<>e then lookup (e, c') else
					(match cl with
					| CLtype (Abs (x,x1), env) -> CLtype (Abs (x, x1), (e1,cl)::env)
					| _ -> cl)
	| (e, []) -> raise (InvalidVar);;

let rec power a b = match (a,b) with
	(a,0) -> 1 |
	(a,b) -> a*(power a (b-1));;

let imp a b = match(a,b) with (true,false) -> false | _-> true;;


(* val absApplied : closure * closure list -> closure * closure list = <fun> *)
let absApplied (cl, s) = match (cl, s) with
	| (CLtype(Abs(x ,e), env), c::c') -> (CLtype(e, (V x, c)::env), c')
	| (_,[]) -> raise InvalidOperation
	| _ -> raise InvalidOperation;;


(* functions defined as :  closure * closure -> closure = <fun> *)
let add (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1+i2), [])
	| _-> raise InvalidOperation;;

let mul (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1*i2), [])
	| _-> raise InvalidOperation;;

let sub (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1-i2), [])
	| _-> raise InvalidOperation;;

let div (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1/i2), [])
	| _-> raise InvalidOperation;;

let exponential (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (power i1 i2), [])
	| _-> raise InvalidOperation;;

let modulus (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1 mod i2), [])
	| _-> raise InvalidOperation;;

let andop (a1, a2) = match (a1,a2) with
	(CLtype(Bl i1, env1), CLtype(Bl i2, env2)) -> CLtype(Bl (bool2myBool ((myBool2bool i1) && (myBool2bool i2))), [])
	| _-> raise InvalidOperation;;

let orop (a1, a2) = match (a1,a2) with
	(CLtype(Bl i1, env1), CLtype(Bl i2, env2)) -> CLtype(Bl (bool2myBool ((myBool2bool i1) && (myBool2bool i2))), [])
	| _-> raise InvalidOperation;;

let notop (a1) = match (a1) with
	(CLtype(Bl i1, env1)) -> CLtype(Bl (bool2myBool (not (myBool2bool i1))), [])
	| _-> raise InvalidOperation;;

let equal (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Bl (if i1==i2 then T else F), [])
	| _-> raise InvalidOperation;;

let greaterthan (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Bl (if i1>i2 then T else F), [])
	| _-> raise InvalidOperation;;

  let rec krivinemachine cl (s:stackCLOS) = match cl with
	| CLtype (Num i, env) -> CLtype (Num i, env)
	| CLtype (Bl b, env) -> CLtype (Bl b, env)
	| CLtype (V v, env) -> krivinemachine (lookup (V (v), env)) s
	| CLtype (Abs(x, e), env) -> 
					let (cl', s') = absApplied (cl, s) in
						krivinemachine cl' s'
	| CLtype (App(e1, e2), env) -> krivinemachine (CLtype(e1, env)) (CLtype(e2, env)::s)
	| CLtype (Plus(e1, e2), env) -> (krivinemachine (add ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Sub(e1, e2), env) -> (krivinemachine (sub ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Times(e1, e2), env) -> (krivinemachine (mul ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Div(e1, e2), env) -> (krivinemachine (div ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Raise(e1, e2), env) -> (krivinemachine (exponential ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Mod(e1, e2), env) -> (krivinemachine (modulus ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (And(e1, e2), env) -> (krivinemachine (andop ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Or(e1, e2), env) -> (krivinemachine (orop ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Not(e1), env) -> (krivinemachine (notop ( (krivinemachine (CLtype(e1, env)) []))) s)
	| CLtype (Eq(e1, e2), env) -> (krivinemachine (equal ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Gt(e1, e2), env) -> (krivinemachine (greaterthan ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (IfTE(e0, e1, e2), env) ->
				let a0 = (krivinemachine (CLtype(e0, env)) []) in
					(match a0 with
					| CLtype(Bl b, env) -> (if (myBool2bool b) then (krivinemachine (CLtype(e1, env)) s) else (krivinemachine (CLtype(e2, env)) s))
					| _ -> raise InvalidOperation)
	| CLtype (Case(e0, el), env) -> 
				let a0 = (krivinemachine (CLtype(e0, env)) []) in
				  (match a0 with
				  | CLtype (Num b, env) -> (krivinemachine (CLtype((List.nth el b), env)) s)
				  | _ -> raise InvalidOperation)
	(* | CLtype (Pair(e0, e1), env) -> CLtype (Pair (e0, e1), env) *)
	(* | CLtype (Fst(e0), env) ->  *)
;;

let rec executekrivine (prog) (env: environmentCLOS): answer = match prog with
	| p -> 
				let cl = krivinemachine (CLtype(p, env)) [] in 
					(match cl with
						| CLtype (Num i, _) -> N i
						| CLtype (Bl b, _) -> B (myBool2bool b)
						(* | CLtype (Pair (i1, i2), _) -> P (i1, i2) *)
						| _-> raise InvalidBigStepAnswerClosure
					)
	| _-> raise ReturnEmpty
;;

let cur_env = [(V "x", CLtype(Num 3, [])); (V "y", CLtype(Num 5, [])); (V "z", CLtype(Bl T, []))];;
let gamma = [(V "x", CLtype(Num 2, [])); (V "y", CLtype(Bl T, [])); (V "x", CLtype(Num 3, []))];;

let p1 = Abs("x", V "x");;
let p2 = Abs("x", Num 4);;
let p3 = App(p1, Num 3);;

let test1a = Plus (Times (Num 3, Num 4), Times (Num 5, Num 6));;
let test1b = Times (Sub (Num 3, Num 4), Times (Num 3, Num 4));; 
let test2 = Or (Not (Bl T), And (Bl T, Or(Bl F, Bl T)));; 
let test3 = Gt (Times (Num 5, Num 6), (Times (Num 3, Num 4)));; 
let test4 = And (Eq(test1a, Num 42), Not test3);;
let test5a = Plus (Times (Plus (Num 1, V "x"), Num 4), Times (Num 5, Num 6));;
let test5b = Plus (Times (Plus (Num 1, V "z"), Num 4), Times (Num 5, Num 6));;

let test6 = IfTE (test3, test1a, test2);;
let test7 = IfTE (test3, test2, test1a);;
let test8 = IfTE (Not test3, test1a, test2);;
let test9 = IfTE (Not test3, test2, test1a);;

let test10 = Pair ( Pair (test1a, test1b), test1b);;
let test11 = Fst (test10);;
let test12 = Snd (test10);;

let test13a = Num 3;;
let test13b = Case (test13a, [test1a; test1b; test2; test3; test4; test5a]);;
let test13c = Case (test13a, [test1a; test1b]);;

let p4 = Abs("x", test5a);;
let p5 = App(p4, Num 7);;


executekrivine p1 cur_env;; (* \x.x *)
executekrivine p2 cur_env;; (* \x.4 *)
executekrivine p3 cur_env;; (* (\x.x).3 -> 3 *)
executekrivine test1a gamma;; (* 42 *)
executekrivine test1b gamma;; (* -12 *)
executekrivine test2 gamma;; (* true *)
executekrivine test3 gamma;; (* true *)
executekrivine test4 gamma;; (* false *)
executekrivine test5a gamma;; (* 42 *)
(* executekrivine test5b gamma;; (* Not_found *)  *)
executekrivine test6 gamma;; (* 42 *)
executekrivine test7 gamma;; (* true *)
executekrivine test8 gamma;; (* true *)
executekrivine test9 gamma;; (* 42 *)
executekrivine test10 gamma;; (* ((42, -12), -12) *)
executekrivine test11 gamma;; (* (42, -12) *)
executekrivine test12 gamma;; (* -12 *)
executekrivine test13a gamma;; (* 3 *)
executekrivine test13b gamma;; (* true *)
(* executekrivine test13c gamma;; (*Failure nth*) *)
executekrivine p4 cur_env;;
executekrivine p5 cur_env;;