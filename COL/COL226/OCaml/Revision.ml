(* let () =
  let in_file = open_in "Code.txt" in
  let line = input_line in_file in
  close_in in_file;
  print_endline line
;; *)

let read_file path = 
  let in_channel = open_in path in
  try
    while true do
      let line = input_line in_channel in
        print_endline line
    done
  with End_of_file -> 
    close_in in_channel

let () = 
  let f = "Code.txt" in
  read_file f
;;
