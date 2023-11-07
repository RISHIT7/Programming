fn main()
{
    // let x: u8 = 64;
    // let y: i8 = -4;

    // println!("{}", x+y);  // dosen't work

    // let x: i64 = 64;
    // let y: i8 = -4;

    // println!("{}", x+y); // dosen't work

    let x: u8 = 255;
    let y: u8 = 10;

    let z: u8 = x / y;
    println!("{}", z); // works and we get z = 25 

    let x = 127_000 as i64;
    let y = 10_i32;

    let z = (x) / (y as i64); // explicit type convertion
    println!("{}", z);

    let x = (i32::MAX as i64) + 1;
    let y = 10_i32;

    let z = x as i32 / y;
    println!("{}", z);  // we get an overflow, and thus we use 2's compiliment wrapping

    
}
