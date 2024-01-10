let rec rev list = match list with | [] -> [] | ele :: list -> rev list @ [ele];;
let rec print_list list = match list with | [] -> "" | el :: list -> string_of_int el ^ print_list list;;
let make_palindrome list = list @ rev list;;
let rec length_of_a_list list = match list with | [] -> 0 | _::list -> 1 + length_of_a_list list;;
let get_first_element list = match list with | [] -> -1 | a::list -> a;;
let drop_one list = match list with | [] -> [] | a::list -> list;;
let rec compare list_a list_b = if (get_first_element list_a = get_first_element list_b && get_first_element list_a = -1) then true else if (get_first_element list_a = get_first_element list_b) then (compare (drop_one list_a) (drop_one list_b)) else false;;
let check_plaindrome list = compare list (rev list);;