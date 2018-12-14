extern crate rand;
extern crate crossbeam;

mod winograd;
mod standard;
mod functions;
use functions::*;
use winograd::*;
use standard::*;
use std::time::Instant;
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 3 || args.len() > 4 {
        panic!("\nExpected 2 args:\n\tNTHREADS\n\tSize of square matrix\n");
    }
    let NTHREADS : usize = args[1].parse().unwrap();
    let size : i32 = args[2].parse().unwrap();

    let m1 = create_random_matrix(size, size);

    let m2 = create_random_matrix(size, size);
    
    let mut instant = Instant::now();
    let mut _2d = winograd(&m1, &m2, NTHREADS);
    let mut time = instant.elapsed();
    println!("Time of winograd {:?} with {} threads", time, NTHREADS);

    instant = Instant::now();
    _2d = standard(&m1, &m2, NTHREADS);
    time = instant.elapsed();
    println!("Time of standard {:?} with {} threads", time, NTHREADS);
}
