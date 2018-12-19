use rand::Rng;
use std::collections::VecDeque;

pub fn create_random_queue(n: i32) -> VecDeque<i32>{
    let mut rng = rand::thread_rng();

    let mut v: VecDeque<i32> = VecDeque::new();
    
    for _i in 0..n { 
        v.push_front(rng.gen_range(0, 10));
    }

    v
}

pub fn factorial(n: i32) -> i32 {
    if n == 0 {
        return 1;
    }

    n*factorial(n-1)
}
