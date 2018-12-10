pub fn winograd(m1: Vec<Vec<i32>>, m2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let r_m1 = m1.len();
    let c_m1 = m1[0].len();
    println!("m1 : {}x{}", r_m1, c_m1);
    let r_m2 = m2.len();
    let c_m2 = m2[0].len();
    println!("m2 : {}x{}", r_m2, c_m2);

    let mut c = Vec::new();

    for _i in 0..r_m1 {
        c.push(Vec::new());
    }
    for mut i in &mut c {
        for _j in 0..c_m2 {
            i.push(0);
        }
    }

    let d = c_m1 / 2;

    let mut rows = vec![0; r_m1];
    println!("Here's array");
    for i in 0..r_m1 {
        rows[i] += m1[i][0] + m1[i][1];
        for j in 1..d {
            rows[i] += m1[i][2*j] * m1[i][2*j+1];
        }
    }
    
    let mut columns = vec![0; c_m2];
    for i in 0..c_m2 {
        columns[i] += m2[0][i]*m2[1][i];
        for j in 1..d {
            columns[i] += m2[2*j][i]*m2[2*j+1][i];
        }
    }

    for i in 0..r_m1 { 
        for j in 0..c_m2 {
            c[i][j] = -rows[i] - columns[j];
            for k in 0..d {
                c[i][j] += (m1[i][2*k] + m2[2*k+1][j]) *
                            (m1[i][2*k+1] + m2[2*k][j]);
            }
        }
    }

    if c_m1%2 {
        for i in 0..r_m1 {
            for j in 0..
        }
    }

    c
}
