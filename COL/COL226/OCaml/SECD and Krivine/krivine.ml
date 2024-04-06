type myBool = T | F;;

type exp = 
            Num of int | Bl of myBool | V of string (* Values *)
          | Plus of exp * exp | Times of exp * exp | Sub of exp * exp | Div of exp * exp | Raise of exp * exp | Mod of exp * exp (* Arithmetics *)
          | And of exp * exp | Or of exp * exp | Not of exp (* Boolean Arithmetics *)
          | Eq of exp * exp | Gt of exp * exp (* Comparison Operators *)
          | IfTE of exp * exp * exp 
          | Abs of string * exp | App of exp * exp (* Abstractions *)
;;

let myBool2bool b = match b with 
| T -> true
| F -> false
;;

let bool2myBool b = match b with 
| true -> T
| false -> F
;;

type environment =  (string * answer) list
and answer = 
  | N of int
  | B of bool
  | P of answer * answer
  | VCLs of string * exp * environmentCLOS
and closure = CLtype of exp*environmentCLOS
and environmentCLOS = (exp*closure) list;;
type stackCLOS = closure list;;

type stack = answer list;;

exception InvalidVar;;
exception InvalidOperation of closure;;
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

(* val absApplied : closure * closure list -> closure * closure list = <fun> *)
let absApplied (cl, s) = match (cl, s) with
	| (CLtype(Abs(x ,e), env), c::c') -> (CLtype(e, (V x, c)::env), c')
  | (CLtype(Abs(x, e), env), []) -> (CLtype(Abs(x, e), env), [])
	| _ -> raise (InvalidOperation cl);;


(* functions defined as :  closure * closure -> closure = <fun> *)
let add (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1+i2), [])
	| _-> raise (InvalidOperation a1);;

let mul (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1*i2), [])
	| _-> raise (InvalidOperation a1);;

let sub (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1-i2), [])
	| _-> raise (InvalidOperation a1);;

let div (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1/i2), [])
	| _-> raise (InvalidOperation a1);;

let exponential (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (power i1 i2), [])
	| _-> raise (InvalidOperation a1);;

let modulus (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Num (i1 mod i2), [])
	| _-> raise (InvalidOperation a1);;

let andop (a1, a2) = match (a1,a2) with
	(CLtype(Bl i1, env1), CLtype(Bl i2, env2)) -> CLtype(Bl (bool2myBool ((myBool2bool i1) && (myBool2bool i2))), [])
	| _-> raise (InvalidOperation a1);;

let orop (a1, a2) = match (a1,a2) with
	(CLtype(Bl i1, env1), CLtype(Bl i2, env2)) -> CLtype(Bl (bool2myBool ((myBool2bool i1) && (myBool2bool i2))), [])
	| _-> raise (InvalidOperation a1);;

let notop (a1) = match (a1) with
	(CLtype(Bl i1, env1)) -> CLtype(Bl (bool2myBool (not (myBool2bool i1))), [])
	| _-> raise (InvalidOperation a1);;

let equal (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Bl (if i1==i2 then T else F), [])
	| _-> raise (InvalidOperation a1);;

let greaterthan (a1, a2) = match (a1,a2) with
	(CLtype(Num i1, env1), CLtype(Num i2, env2)) -> CLtype(Bl (if i1>i2 then T else F), [])
	| _-> raise (InvalidOperation a1);;

  let rec krivinemachine cl (s:stackCLOS) = match cl, s with
	| CLtype (Num i, env), s -> CLtype (Num i, env)
	| CLtype (Bl b, env), s -> CLtype (Bl b, env)
	| CLtype (V v, env), s -> krivinemachine (lookup (V (v), env)) s
  | CLtype (Abs(x, e), env), [] -> CLtype (Abs(x, e), env)
	| CLtype (Abs(x, e), env), s -> 
					let (cl', s') = absApplied (cl, s) in
						krivinemachine cl' s'
	| CLtype (App(e1, e2), env), s -> krivinemachine (CLtype(e1, env)) (CLtype(e2, env)::s)
	| CLtype (Plus(e1, e2), env), s -> (krivinemachine (add ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Sub(e1, e2), env), s -> (krivinemachine (sub ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Times(e1, e2), env), s -> (krivinemachine (mul ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Div(e1, e2), env), s -> (krivinemachine (div ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Raise(e1, e2), env), s -> (krivinemachine (exponential ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Mod(e1, e2), env), s -> (krivinemachine (modulus ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (And(e1, e2), env), s -> (krivinemachine (andop ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Or(e1, e2), env), s -> (krivinemachine (orop ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Not(e1), env), s -> (krivinemachine (notop ( (krivinemachine (CLtype(e1, env)) []))) s)
	| CLtype (Eq(e1, e2), env), s -> (krivinemachine (equal ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (Gt(e1, e2), env), s -> (krivinemachine (greaterthan ((krivinemachine (CLtype(e1, env)) []), (krivinemachine (CLtype(e2, env)) []))) s)
	| CLtype (IfTE(e0, e1, e2), env), s ->
				let a0 = (krivinemachine (CLtype(e0, env)) []) in
					(match a0 with
					| CLtype(Bl b, env) -> (if (myBool2bool b) then (krivinemachine (CLtype(e1, env)) s) else (krivinemachine (CLtype(e2, env)) s))
					| _ -> raise (InvalidOperation a0))
;;

let rec executekrivine (prog) (env: environmentCLOS): answer = match prog with
	| p -> 
				let cl = krivinemachine (CLtype(p, env)) [] in 
					(match cl with
						| CLtype (Num i, _) -> N i
						| CLtype (Bl b, _) -> B (myBool2bool b)
            | CLtype (Abs(x, exp), env) -> VCLs(x, exp, env)
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

let p4 = Abs("x", test5a);;
let p5 = App(p4, Num 7);;

(* let x = executekrivine test1a cur_env;; *)
(* let x = executekrivine test1b cur_env;; *)
(* let x = executekrivine test2 cur_env;; *)
(* let x = executekrivine test3 cur_env;; *)
(* let x = executekrivine test4 cur_env;; *)
(* let x = executekrivine test5a cur_env;; *)
(* let x = executekrivine test5b cur_env;; (* Invalid Op *) *)
(* let x = executekrivine test6 cur_env;;
let x = executekrivine test7 cur_env;;
let x = executekrivine test8 cur_env;;
let x = executekrivine test9 cur_env;;
let x = executekrivine p4 cur_env;;
let x = executekrivine p5 cur_env;; *)