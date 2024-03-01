{
    open Parser;;
    exception InvalidToken of char;;
}

let alpha_num = ['A'-'Z' 'a'-'z' '0'-'9' '_' '\'']
let var = ['A'-'Z'](alpha_num*)
let cons = ['a'-'z'](alpha_num*) | ("\"" [^ '\"']+ "\"" )
(* the latter part matches a string [^'\"'] matches one or more characters that are not double quotes *)
let skip = [' ' '\t' '\n' '\r']+
let number = '0'|['1'-'9']['0'-'9']*

rule token = parse
    | sp
        { token lexbuf }
    | ['+']
        { PLUS }
    | ['-']
        { MINUS }
    | ['*']
        { ASTERISK }
    | ['/']
        { SLASH }
    | var as lxm
        { IDENT(lxm) }
    | cons as lxm
        { CONS(lxm) }
    | number as lxm
        { INTEGER(lxm) }
    | ['(']
        { LEFTBRACKET }
    | [')']
        { RIGHTBRACKET }
    | ['[']
        { LEFTSQUARE }
    | [']']
        { RIGHTSQUARE }
    | [',']
        { COMMA }
    | ['=']
        { ASSIGN }
    | ['<']
        { LESSTHAN }
    | ['>']
        { GREATERTHAN }
    | "!="
        { NOTEQUAL }
    | ['|']
        { PIPE }
    | ['!']
        { BANG }
    | ['.']
        { STOP }
    | ":-"
        { COND }
    | ['%']
        { PERCENTAGE }
    | "/*"
        { COMMENTOPEN }
    | "*/"
        { COMMENTCLOSE }
    | _ as lxm
        {raise (InvalidToken lxm)}
    | eof
        { EOF }

and oneLineComment = parse
      eof
        { EOF }
    | ['\n']
        {token lexbuf}
    | _
        {oneLineComment lexbuf}

and multiLinecomment = parse
      eof
        { EOF }
    | "*/"
        { if depth = 0 then token lexbuf 
          else multiLinecomment (depth-1) lexbuf }
    | "/*"
        { multiLinecomment (depth+1) lexbuf }
    | _
        { multiLinecomment depth lexbuf }