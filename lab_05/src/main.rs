extern crate rand;
extern crate crossbeam;

mod winograd;
mod standard;
mod functions;
use functions::*;
use winograd::*;
use standard::*;
use std::time::Instant;

static NTHREADS: usize = 4;

fn main() {
    let m1 = create_random_matrix(400, 400);

    let m2 = create_random_matrix(400, 400);
    
    let mut instant = Instant::now();
    let mut _2d = winograd(&m1, &m2, NTHREADS);
    let mut time = instant.elapsed();
    println!("Time of winograd {:?} with {} threads", time, NTHREADS);

    instant = Instant::now();
    _2d = standard(&m1, &m2, NTHREADS);
    time = instant.elapsed();
    println!("Time of winograd {:?} with {} threads", time, NTHREADS);
}
