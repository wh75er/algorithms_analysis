use std::sync::{Arc, Mutex};
use std::collections::VecDeque;
use std::time::{Duration, Instant};
use std::thread;

use functions::factorial;

pub fn level_a_thread(queue_level_a_mutex: Arc<Mutex<&mut &mut VecDeque<i32>>>, 
                    queue_level_b_mutex: Arc<Mutex<&mut VecDeque<i32>>>,
                    log_mutex: Arc<Mutex<&mut String>>) {

    let now = Instant::now();

    let mut count = 0;
    let mut queue_level_a = queue_level_a_mutex.lock().unwrap();
    while !(*queue_level_a).is_empty() {
        {
            let mut queue_level_b = queue_level_b_mutex.lock().unwrap();
            let n = (*queue_level_a).pop_back().unwrap();
            let result = factorial(n);
            (*queue_level_b).push_front(result);

            insert_log(log_mutex.clone(), count, "loaded to level B queue", now.elapsed());

            count+=1;
        }
        thread::sleep(Duration::from_millis(2));
    }
    println!("Thread a is finished");
}

pub fn level_b_thread(queue_level_a_mutex: Arc<Mutex<&mut &mut VecDeque<i32>>>, 
                    queue_level_b_mutex: Arc<Mutex<&mut VecDeque<i32>>>,
                    queue_level_c_mutex: Arc<Mutex<&mut VecDeque<i32>>>,
                    log_mutex: Arc<Mutex<&mut String>>) {

    let now = Instant::now();

    thread::sleep(Duration::from_millis(10));
    let mut count = 0;
    while queue_level_a_mutex.try_lock().is_err() {
        {
            let mut queue_level_b = queue_level_b_mutex.lock().unwrap();
            if !(*queue_level_b).is_empty() {
                {
                    let mut queue_level_c = queue_level_c_mutex.lock().unwrap();
                    let mut num = (*queue_level_b).pop_back().unwrap();
                    num *= 2;
                    (*queue_level_c).push_front(num);

                    insert_log(log_mutex.clone(), count, "loaded to level C queue", now.elapsed());
                    count+=1;
                }
            }
        }
        thread::sleep(Duration::from_millis(2));
    }
    let mut queue_level_b = queue_level_b_mutex.lock().unwrap();
    while !(*queue_level_b).is_empty() {
        {
            let mut queue_level_c = queue_level_c_mutex.lock().unwrap();
            let mut num = (*queue_level_b).pop_back().unwrap();
            num *= 2;
            (*queue_level_c).push_front(num);

            insert_log(log_mutex.clone(), count, "loaded to level C queue", now.elapsed());
            count += 1;
        }
    }
    println!("Thread b is finished");
}

pub fn level_c_thread(queue_level_c_mutex: Arc<Mutex<&mut VecDeque<i32>>>, 
                    result_mutex: Arc<Mutex<&mut VecDeque<i32>>>,
                    size: usize,
                    log_mutex: Arc<Mutex<&mut String>>) {

    let now = Instant::now();

    let mut result = result_mutex.lock().unwrap();
    let mut count = 0;
    while count < size {
        {
            let mut queue_level_c = queue_level_c_mutex.lock().unwrap();
            if !(*queue_level_c).is_empty() {
                let num = (*queue_level_c).pop_back().unwrap();
                if num%3 == 0 {
                    (*result).push_back(num);
                    insert_log(log_mutex.clone(), count, "loaded to result", now.elapsed());
                }

                count+=1;
            }
        }
        thread::sleep(Duration::from_millis(2));
    }
    println!("Thread c is finished");
}

fn insert_log(log_mutex: Arc<Mutex<&mut String>>, obj_number: usize, text: &'static str, time: std::time::Duration) {
    let mut mutex = log_mutex.lock().unwrap();
    **mutex += &format!("{:?}:\tObject {} was {}\n", time, obj_number+1, text.to_string())
}
