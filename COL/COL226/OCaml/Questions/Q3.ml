let snd p = match p with
| (_, y)  -> y
| _ -> "idiot";;

let y = snd ("I", "am") ;;
let () = print_endline(y);;

