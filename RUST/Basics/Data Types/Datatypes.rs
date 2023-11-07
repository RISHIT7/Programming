fn main() {
    let x: i32 = 2; // integer 32, we have 8, 16, 64, 128, etc.
    println!("{}", x);
    // u32, is an unsigned integer
    // f32, signle prec floating point number
    // f64, double prec floating point number
    // bool , obvious, true or false
    // characters
    let letter: char = 'a';
    println!("{}", letter);

    let mut tup: (i32, bool, char) = (1, true, 'a');
    let tup1: (i8, bool, char) = (1, true, 'a'); // theese can not be assigned to each other, as obvious
                                               // println!("{}", tup); // would give an error

    tup.1 = false;

    println!("{}", tup.0);
    println!("{}", tup.2);
    println!("{}", tup.1);

    let arr: [i32; 5] = [1, 2, 3, 4, 5]; // equivalent to int arr[5] = {1, 2, 3, 4, 5};
}
