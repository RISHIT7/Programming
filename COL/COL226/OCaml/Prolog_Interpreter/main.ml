open Interpreter;;
open Lexer;;
open Parser;;

let () = 
  if Array.length Sys.argv <> 2 then
    Printf.printf "Usage: %s <input_file>\n" Sys.argv.(0)
  else
    let filename = Sys.argv.(1) in
    let ast = parse_file filename in
    Interpreter.print_program ast
    ;

let parse_file filename = 
  let input_channel = open_in filename in
  let lexbuf = Lexing.from_channel input_channel in
  try
    let result = Parser.program Lexer.token lexbuf in
    let prog = modifyInitialProg result in
    try 
      while (true) do
        print_string "?-";
        let line = read_line() in
        if line = "halt." then exit 0
        else try
          let g = Parser.goal Lexer.token (Lexing.from_string line) in
          match (interpret_goal prog g) with
          | (true, _) -> print_string "true.\n"
          | (false, _) -> print_string "false.\n"
        with e -> Printf.printf "%s\n" (Printexc.to_string e)
      done;
    close_in input_channel;
    result
  with
  | Parsing.Parse_error ->
    close_in input_channel;
    failwith "Parsing Error"
;;