pub struct PascalsTriangle {
    row_count: usize
}

impl PascalsTriangle {
    pub fn new(row_count: usize) -> Self {
        Self {
            row_count
        }
    }

    pub fn rows(&self) -> Vec<Vec<u32>> {
        let mut rv: Vec<Vec<u32>> = Vec::with_capacity(self.row_count);
        
        for n in 0..self.row_count {
            rv.push(n_row(n));
        }

        rv
    }

}

fn n_row(n: usize) -> Vec<u32> {
    let mut rv: Vec<u32> = Vec::with_capacity(n);
    
    for k in 0..n+1 {
        rv.push(n_choose_k(n, k));
    }
    
    rv
}

fn factorial(n: usize) -> usize {
    let mut p = 1;
    for i in 2..n+1 {
        p *= i;
    }
    p
}

fn n_choose_k(n: usize, k: usize) -> u32 {
    (factorial(n) / (factorial(k) * factorial(n - k))) as u32
}