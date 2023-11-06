fn main()
{
    let x = 4; // implicit variable assignment, remember rust is statically tyoed
    // types assigned by compiler at compile time

    // explicit assignement
    let y: u32 = 4;

    println!("x is : {}", x);

    // BUT!!
    x = 5;
    println!("x is : {}", x);
}