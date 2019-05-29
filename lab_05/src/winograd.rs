use std::sync::Arc;
use crossbeam::thread;

struct Shitpointer(*mut i32);
unsafe impl Send for Shitpointer {}
struct ShitpointerDouble(*mut Vec<i32>);
unsafe impl Send for ShitpointerDouble {}

pub fn winograd(m1: &Vec<Vec<i32>>, m2: &Vec<Vec<i32>>, nthreads: usize) -> Vec<Vec<i32>> {
    let r_m1 = m1.len();
    let c_m1 = m1[0].len();
    let r_m2 = m2.len();
    let c_m2 = m2[0].len();

    if c_m1 != r_m2 {
        panic!("Unable multiply matrices. Incorrect sizes");
    }
    
    if nthreads > r_m1 || nthreads > c_m1 ||
        nthreads > r_m2 || nthreads > c_m2 {
        panic!("Unable to parallel process, number of threads more than
                amount of elements");
    }


    let mut c = vec![vec![0; c_m2]; r_m1];
    let mut rows = vec![0; r_m1];
    let mut columns = vec![0; c_m2];

    let d = c_m1 / 2;

    let m1_arced = Arc::new(m1.clone()); 
    let m2_arced = Arc::new(m2.clone()); 

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
            let mut rows_ptr = Shitpointer(rows.as_mut_ptr());
            let mut columns_ptr = Shitpointer(columns.as_mut_ptr());
            threads.push(
            scope.spawn(move |_| unsafe { 

                for i in r_m1_from..r_m1_to {
                    *rows_ptr.0.offset(i as isize) += m1_data[i][0] * m1_data[i][1];
                    for j in 1..d {
                        *rows_ptr.0.offset(i as isize) += m1_data[i][2*j] * m1_data[i][2*j+1];
                    }
                }
    
                for i in c_m2_from..c_m2_to {
                    *columns_ptr.0.offset(i as isize) += m2_data[0][i] * m2_data[1][i];
                    for j in 1..d {
                        *columns_ptr.0.offset(i as isize) += m2_data[2*j][i] * m2_data[2*j+1][i];
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


    let r_m1_shift = r_m1 / nthreads;
    let mut r_m1_from = 0;
    let mut r_m1_to = r_m1_shift;

    thread::scope(|scope| {
        let mut threads_second = vec![];

        for m in 0..nthreads {
            let m1_data = m1_arced.clone();
            let m2_data = m2_arced.clone();
            let mut rows_ptr = Shitpointer(rows.as_mut_ptr());
            let mut columns_ptr = Shitpointer(columns.as_mut_ptr());
            let mut c_ptr = ShitpointerDouble(c.as_mut_ptr());
            threads_second.push(
            scope.spawn(move |_| unsafe { 

                for i in r_m1_from..r_m1_to { 
                    for j in 0..c_m2 {
                        (*c_ptr.0.offset(i as isize))[j] = -(*rows_ptr.0.offset(i as isize)) - (*columns_ptr.0.offset(j as isize));
                        for k in 0..d {
                            (*c_ptr.0.offset(i as isize))[j] += (m1_data[i][2*k] + m2_data[2*k+1][j]) *
                                (m1_data[i][2*k+1] + m2_data[2*k][j]);
                        }
                    }
                }
    
                if c_m1%2 == 1 {
                    for i in r_m1_from..r_m1_to {
                        for j in 0..c_m2 {
                            (*c_ptr.0.offset(i as isize))[j] += m1_data[i][c_m1-1] * m2_data[c_m1-1][j];
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

        for thread in threads_second {
            thread.join().unwrap()
        }
    }).unwrap();
    
    c
}
