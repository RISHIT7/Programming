{
    open Token
}

rule token = parse
   | [''']['a'-'z' '_' '0'-'9']+ as lxm
        { Illegal(lxm) }
   | ['A'-'Z']['a'-'z' '_' '0'-'9' 'A'-'Z']+ as lxm
        { Illegal(lxm) }
   | [' ' '\t']+
        { token lexbuf }
   | ['\n' '\r']
        { NewLine }
   | ['+']
        { Plus }
   | [''']
        { InvertedComma }
   | ['"']
        { DoubleInvertedComma }
   | [':']
        { Colon }
   | ['-']
        { Minus }
   | ['*']
        { Asterisk }
   | ['/']
        { Slash }
   | ['#']
        { Hashtags }
   | "true"
        { Bool(True)}
   | "false"
        { Bool(False)}
   | ['0'-'9']+ as lxm
       { Integers(int_of_string (lxm)) }
   | ['=']
        { Assign }
   | ['|']
        { Or }
   | ['&']
        { And }
   | ['~']
        { Not }
   | ['!']
        { Bang }
   | ['<']
        { LessThan }
   | ['>']
        { GreaterThan }
   | "=="
        { Equal }
   | "!="
        { NotEqual }
   | "<="
        { NotEqual }
   | ">="
        { NotEqual }
   | [',']
        { Comma }
   | [';']
        { Semicolon }
   | ['(']
        { LeftBracket }
   | [')']
        { RightBracket }
   | ['[']
        { LeftSquare }
   | [']']
        { RightSquare }
   | ['{']
        { LeftCurly }
   | ['}']
        { RightCurly }
   | "fn"
        { Function }
   | "let"
        { Let }
   | "if"
        { If }
   | "else"
        { Else }
   | "return"
        { Return }
   | ['a'-'z' '_']['a'-'z' '_' '0'-'9' ''']+ as lxm
        { Ident(lxm) }
   | ['a'-'z' '_'] as lxm
        { Ident(String.make 1 lxm) }
   | ['.']
        { Dot }
   | eof
        { EOF }
   | _ as lxm
        { Illegal(String.make 1 lxm) }