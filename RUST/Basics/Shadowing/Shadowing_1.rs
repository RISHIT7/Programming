fn main()
{
    let x = 4;
    println!("x is: {}", x);

    {
        let x = 2;
        println!("x is: {}", x);
    }

    let x = x + 1;
    println!("x is: {}", x); // -> 5
}