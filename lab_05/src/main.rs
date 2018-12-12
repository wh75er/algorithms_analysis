extern crate rand;
extern crate crossbeam;

mod winograd;
mod standard;
mod functions;
use functions::*;
use winograd::*;
use standard::*;

static NTHREADS: usize = 6;

fn main() {
    println!("Hello, world!");
    
    let m1 = create_random_matrix(6, 6); //2, 3
    println!("This is the first random matrix {:?}", m1);

    let m2 = create_random_matrix(6, 6); //3 3
    println!("This is the second random matrix {:?}", m2);
    
    let mut _2d = winograd(&m1, &m2, NTHREADS);
    println!("Result matrix(winograd) is : {:?}", _2d);

    _2d = standard(&m1, &m2, NTHREADS);
    println!("Result matrix(standard) is : {:?}", _2d);
}
