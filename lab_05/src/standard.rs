use std::sync::{Arc, Mutex};
use crossbeam::thread;

pub fn standard(m1: &Vec<Vec<i32>>, m2: &Vec<Vec<i32>>, nthreads: usize) -> Vec<Vec<i32>> {
    let r_m1 = m1.len();
    let c_m1 = m1[0].len();
    println!("\nm1 : {}x{}", r_m1, c_m1);
    let r_m2 = m2.len();
    let c_m2 = m2[0].len();
    println!("m2 : {}x{}", r_m2, c_m2);

    if c_m1 != r_m2 {
        panic!("Unable multiply matrices. Incorrect sizes");
    }

    if nthreads > r_m1 || nthreads > c_m1 ||
        nthreads > r_m2 || nthreads > c_m2 {
        panic!("Unable to parallel process, number of threads more than
                amount of elements");
    }

    let mut c = vec![vec![0; c_m2]; r_m1];
    
    for i in 0..r_m1 {
        for j in 0..c_m2 {
            for k in 0..c_m1{
                c[i][j] += m1[i][k] * m2[k][j]
            }
        }
    }
    
    c
}
