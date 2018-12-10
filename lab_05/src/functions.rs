use rand::Rng;

pub fn create_random_matrix(a: i32, b: i32) -> Vec<Vec<i32>> {
    let mut rng = rand::thread_rng();

    let mut v = Vec::new();
    for _i in 0..a {
        v.push(Vec::new());
    }
    for mut i in &mut v {
        for _j in 0..b {
            i.push(rng.gen_range(0, 10));
        }
    }

    v
}
