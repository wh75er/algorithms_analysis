pub fn standard(m1: &Vec<Vec<i32>>, m2: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let r_m1 = m1.len();
    let c_m1 = m1[0].len();
    println!("m1 : {}x{}", r_m1, c_m1);
    let r_m2 = m2.len();
    let c_m2 = m2[0].len();
    println!("m2 : {}x{}", r_m2, c_m2);

    if c_m1 != r_m2 {
        panic!("Unable multiply matrices. Incorrect sizes");
    }

    let mut c = vec![vec![0; c_m2]; r_m1];
    
    let mut value = 0; 
    for i in 0..r_m1 {
        for j in 0..c_m2 {
            for k in 0..c_m1{
                value += m1[i][k] * m2[k][j]
            }
            c[i][j] = value;
            value = 0;
        }
    }
    
    c
}
