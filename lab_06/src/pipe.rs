use std::sync::{Arc, Mutex};
use crossbeam::thread;

use thread_handlers::*;
use std::collections::VecDeque;

pub fn pipe(mut queue: &mut VecDeque<i32>) -> (VecDeque<i32>, String) {

    let queue_size = queue.len();

    let mut queue_level_b: VecDeque<i32> = VecDeque::new();
    let mut queue_level_c: VecDeque<i32> = VecDeque::new();
    let mut result: VecDeque<i32> = VecDeque::new();
    let mut log: String = "".to_string();


    thread::scope(|scope| {
        let queue_level_a_mutex = Arc::new(Mutex::new(&mut queue));
        let queue_level_b_mutex = Arc::new(Mutex::new(&mut queue_level_b));
        let queue_level_c_mutex = Arc::new(Mutex::new(&mut queue_level_c));
        let result_mutex = Arc::new(Mutex::new(&mut result));
        let log_mutex = Arc::new(Mutex::new(&mut log));

        let mut threads = vec![];
        let cloned_a = queue_level_a_mutex.clone();
        let cloned_b = queue_level_b_mutex.clone();
        let cloned_log = log_mutex.clone();
        threads.push(
        scope.spawn(move |_| level_a_thread(cloned_a, cloned_b, cloned_log))
        );

        let cloned_a = queue_level_a_mutex.clone();
        let cloned_b = queue_level_b_mutex.clone();
        let cloned_c = queue_level_c_mutex.clone();
        let cloned_log = log_mutex.clone();
        threads.push(
        scope.spawn(move |_| level_b_thread(cloned_a, cloned_b, cloned_c, cloned_log))
        );

        let cloned_c = queue_level_c_mutex.clone();
        let cloned_result = result_mutex.clone();
        let cloned_log = log_mutex.clone();
        threads.push(
        scope.spawn(move |_| level_c_thread(cloned_c, cloned_result, queue_size, cloned_log))
        );

        for thread in threads {
            thread.join().unwrap()
        }
    }).unwrap();
       
    (result, log)
}
