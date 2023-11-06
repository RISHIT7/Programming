fn main()
{
    let x = 4; // implicit variable assignment, remember rust is statically tyoed
    // types assigned by compiler at compile time

    // explicit assignement
    let y: u32 = 4;

    println!("x is : {}", x);

    let x = 5; // this does NOT give an error in rust
    println!("x is : {}", x);
}