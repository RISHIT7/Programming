{
    open Parser
}

let digit = ['0'-'9']

rule token = parse
| ['\n']
    { NEWLINE }
| ['\t' ' ' '_']+
    { token lexbuf }
| ['(']
    { LPAREN }
| [')']
    { RPAREN }
| digit+
| "." digit+
| digit+ "." digit* as num
  { NUM (float_of_string num) }
| ['+']
    { PLUS }
| ['-']
    { MINUS }
| ['*']
    { MULTIPLY }
| ['/']
    { DIVIDE }
| ['^']
    { CARET }
| eof
    { raise End_of_file }