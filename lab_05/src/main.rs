extern crate rand;

mod winograd;
mod standard;
mod functions;
use functions::*;
use winograd::*;
use standard::*;

use std::thread;
use std::time::Duration;

fn main() {
    println!("Hello, world!");
    
    let m1 = create_random_matrix(2, 3);
    println!("This is the first random matrix {:?}", m1);

    let m2 = create_random_matrix(3, 3);
    println!("This is the second random matrix {:?}", m2);
    
    let mut _2d = winograd(&m1, &m2);
    println!("Result matrix(winograd) is : {:?}", _2d);

    _2d = standard(&m1, &m2);
    println!("Result matrix(standard) is : {:?}", _2d);
}
