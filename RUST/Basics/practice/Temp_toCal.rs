use std::io;

fn main()
{
    let mut far = String::new();

    io::stdin().read_line(&mut far).expect("failed to read line");

    let int_input:i64 = far.trim().parse().unwrap();

    let cal : i64 = ((int_input - 32)*5)/9;

    println!("{}, {}", int_input, cal);
}