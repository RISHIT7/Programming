let rec evens list =  match list with
| [] -> []
| _ :: [] -> []
| _ :: a :: list -> a :: evens list;;

let rec print_list list = match list with
| [] -> ""
| el :: list -> string_of_int el ^ print_list list;;


let () = print_endline (print_list (evens [2;4;2;4;2]));;