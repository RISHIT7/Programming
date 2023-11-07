use std::io;
// std crate, io module

// package = library = crate ( in RUST ) <- has a  module
// Prelude is kind of like the include <basics>, but io is not a part of this prelude
fn main()
{
    println!("Hello, world!");

    let mut input = String::new(); // package <- module <- function

    io::stdin().read_line(&mut input).expect("failed to read line"); // mutable reference to input variable
    println!("{}", input);
}