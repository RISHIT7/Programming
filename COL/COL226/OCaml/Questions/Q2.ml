let test x = match x with
| "foo" -> 1
| "dat" -> 2
| _ -> 3;;

let y = test "panda";;
let () = print_string(string_of_int y ^ "\n");;