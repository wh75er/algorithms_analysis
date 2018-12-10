extern crate rand;

mod winograd;
mod functions;
use functions::*;
use winograd::*;

fn main() {
    println!("Hello, world!");
    
    let m1 = create_random_matrix(3, 1);
    println!("This is the first random matrix {:?}", m1);

    let m2 = create_random_matrix(1, 4);
    println!("This is the second random matrix {:?}", m2);
    
    let mut _2d = winograd(m1, m2);
    println!("{:?}", _2d);

    for i in _2d {
        for j in 0..i.len()+1 {
            println!("{}", j);
        }
    }
}
