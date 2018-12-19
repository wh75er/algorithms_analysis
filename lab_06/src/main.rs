extern crate rand;
extern crate crossbeam;

mod thread_handlers;
mod pipe;
mod functions;
use functions::*;
use pipe::*;

use std::fs;
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        panic!("\nExpected 1 argument:\n\tSize of queue\n");
    }
    let size = args[1].parse().unwrap(); 
    
    let mut queue = create_random_queue(size);
    
    let tuple = pipe(&mut queue);
    println!("result is {:?} \nlog:\n{}", tuple.0, tuple.1);

    fs::write("logs", tuple.1).expect("Unable to write file");
}
