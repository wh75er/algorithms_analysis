use std::sync::Arc;
use crossbeam::thread;

struct Shitpointer(*mut Vec<i32>);
unsafe impl Send for Shitpointer {}

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

    let m1_arced = Arc::new(m1.clone());
    let m2_arced = Arc::new(m2.clone());

    let mut c = vec![vec![0; c_m2]; r_m1];

    let r_m1_shift = r_m1 / nthreads;
    let mut r_m1_from = 0;
    let mut r_m1_to = r_m1_shift;

    thread::scope(|scope| {
        let mut threads = vec![];
        for m in 0..nthreads {
            let m1_data = m1_arced.clone();
            let m2_data = m2_arced.clone();
            let c_ptr = Shitpointer(c.as_mut_ptr());
            threads.push(
            scope.spawn(move |_| unsafe {
                for i in r_m1_from..r_m1_to {
                    for j in 0..c_m2 {
                        for k in 0..c_m1{
                            (*c_ptr.0.offset(i as isize))[j] += 
                                m1_data[i][k] * m2_data[k][j];
                        }
                    }
                }
            }));

            r_m1_from = r_m1_to;                          // Rows shift for 1 matrix
            r_m1_to += r_m1_shift;

            if m+2 == nthreads {                          // Check if this is the last iteration;
                r_m1_to = r_m1;
            }
        }

        for thread in threads {
            thread.join().unwrap()
        }
    }).unwrap();
    
    c
}
