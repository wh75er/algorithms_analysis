//use std::thread;
use std::sync::{Arc, Mutex};
use crossbeam::thread;

pub fn winograd(m1: &Vec<Vec<i32>>, m2: &Vec<Vec<i32>>, nthreads: usize) -> Vec<Vec<i32>> {
    let r_m1 = m1.len();
    let c_m1 = m1[0].len();
    println!("m1 : {}x{}", r_m1, c_m1);
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

    let mut c_vec = vec![vec![0; c_m2]; r_m1];
    let mut rows_vec = vec![0; r_m1];
    let mut columns_vec = vec![0; c_m2];

    let d = c_m1 / 2;

    let m1_arced = Arc::new(m1.clone()); 
    let m2_arced = Arc::new(m2.clone()); 
    
    {
    let c_arced = Arc::new(Mutex::new(&mut c_vec));
    let rows_arced = Arc::new(Mutex::new(&mut rows_vec));
    let columns_arced = Arc::new(Mutex::new(&mut columns_vec));

    let r_m1_shift = r_m1 / nthreads;
    let mut r_m1_from = 0;
    let mut r_m1_to = r_m1_shift;

    let c_m2_shift = c_m2 / nthreads;
    let mut c_m2_from = 0;
    let mut c_m2_to = c_m2_shift;

    thread::scope(|scope| {
    let mut threads = vec![];
    for m in 0..nthreads {
        let m1_data = m1_arced.clone();
        let m2_data = m2_arced.clone();
        let c_mutex = c_arced.clone();
        let rows_mutex = rows_arced.clone();
        let columns_mutex = columns_arced.clone();
        threads.push(
        scope.spawn(move |_| {
            let mut rows = rows_mutex.lock().unwrap();
            for i in r_m1_from..r_m1_to {
                (*rows)[i] += m1_data[i][0] * m1_data[i][1];
                for j in 1..d {
                    (*rows)[i] += m1_data[i][2*j] * m1_data[i][2*j+1];
                    //println!("loop inside");
                }
            }

            //println!("d is {:?}", d);
            //println!("rows here {:?}", *rows);
            //println!("rows_m1_from {:?}, rows_m1_to {:?}", r_m1_from, r_m1_to);
            //println!("columns_m2_from {:?}, columns_m2_to {:?}", c_m2_from, c_m2_to);
        
            let mut columns = columns_mutex.lock().unwrap();
            for i in c_m2_from..c_m2_to {
                (*columns)[i] += m2_data[0][i] * m2_data[1][i];
                for j in 1..d {
                    (*columns)[i] += m2_data[2*j][i] * m2_data[2*j+1][i];
                }
            }
        
            let mut c = c_mutex.lock().unwrap();
            for i in r_m1_from..r_m1_to { 
                for j in c_m2_from..c_m2_to {
                    (*c)[i][j] = -(*rows)[i] - (*columns)[j];
                    for k in 0..d {
                        (*c)[i][j] += (m1_data[i][2*k] + m2_data[2*k+1][j]) *
                                    (m1_data[i][2*k+1] + m2_data[2*k][j]);
                    }
                }
            }
        }));

        c_m2_from = c_m2_to;                          // Columns shift for 2 matrix
        c_m2_to += c_m2_shift;

        r_m1_from = r_m1_to;                          // Rows shift for 1 matrix
        r_m1_to += r_m1_shift;

        if m+2 == nthreads {                          // Check if this is the last iteration;
            c_m2_to = c_m2;
            r_m1_to = r_m1;
        }
    }
    for thread in threads {
        thread.join().unwrap()
    }
    }).unwrap();
    }


    println!("Current reslut matrix : {:?}", c_vec);
    if c_m1%2 == 1 {
        for i in 0..r_m1 {
            for j in 0..c_m2 {
                c_vec[i][j] += m1[i][c_m1-1] * m2[c_m1-1][j];
            }
        }
    }

    c_vec
}
