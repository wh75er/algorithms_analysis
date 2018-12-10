pub fn winograd(m1: Vec<Vec<i32>>, m2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut c = Vec::new();

    for _i in 0..m1.len() {
        c.push(Vec::new());
    }
    let row = &m2[0];
    for mut i in &mut c {
        for _j in 0..row.len() {
            i.push(0);
        }
    }

    println!("Hello world");

    c
}
