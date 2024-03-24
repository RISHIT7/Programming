type exp = V of string | Abs of string * exp | App of exp * exp;;

type opcode =  LOOKUP of string |  APP  | MKCLOS of string * opcode list  |  RET;;