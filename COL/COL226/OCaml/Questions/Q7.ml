(* Check Exsistance *)
let get_first_tuple tuple = match tuple with | (a, b) -> a;;
let get_second_tuple tuple = match tuple with | (a, b) -> b;;
let rec check_existance_helper element list pos = match list with | [] -> (false, -1) | a::list -> if element = a then (true, pos) else check_existance_helper element list (pos + 1);;
let check_existance element list = check_existance_helper element list 0;;

(* Drop at *)
let get_first_list list = match list with | a::list -> a | [] -> -1;;
let drop_first_list list = match list with | a::list -> list | [] -> [-1];;
let rec drop_at_helper list buffer pos = if pos <> 0 && list = [] then [-1] else if pos = 0 then buffer @ (drop_first_list list) else if pos > 0 && list <> [] then drop_at_helper (drop_first_list list) (buffer @ [get_first_list list]) (pos-1) else [];;
let drop_at list pos = drop_at_helper list [] pos

(* Drop element *)
let drop_element list element = match get_first_tuple (check_existance element list) with | true -> drop_at list (get_second_tuple (check_existance element list)) | false -> list;;

(* Make Set *)
let rec make_set_helper list buffer = match list with | a::list -> if get_first_tuple(check_existance a list) then make_set_helper list buffer else make_set_helper list (buffer @ [a]) | [] -> buffer;;
let make_set list = make_set_helper list [];;
let rec print_list list = match list with | [] -> "" | el :: list -> string_of_int el ^ print_list list;;
let () = print_endline (print_list (make_set [1;2;3;3;4;5;6;7;8;8]));;