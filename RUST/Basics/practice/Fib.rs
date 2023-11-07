use std::io;
fn main()
{
    let mut n = String::new();
    io::stdin().read_line(&mut n).expect("couldn't read line");

    let int_n:i64 = n.trim().parse().unwrap();

    let mut a:i64 = 0;
    let mut b:i64 = 1;
    let mut i:i64 = 1;
    while i < int_n {
        let c:i64 = a + b;
        a = b;
        b = c;

        i += 1;
    }

    println!("The {}th number is: {}", int_n, a);
}