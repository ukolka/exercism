pub fn find_saddle_points(input: &[Vec<u64>]) -> Vec<(usize, usize)> {
    assert!(input.len() > 0);

    if input[0].len() == 0 {
        return vec![];
    }

    let m = input.len();
    let n = input[0].len();

    let mut result = vec![];
    
    for i in 0..m {
        for j in 0..n {
            if is_saddle_point(input, i, j) {
                result.push((i, j));
            }
        }
    }

    result
}

fn is_saddle_point(input: &[Vec<u64>], i: usize, j: usize) -> bool {
    let val = input[i][j];

    let nrows = input.len();
    let ncols = input[0].len();

    let colrep = vec![i; ncols];
    let rowrep = vec![j; nrows];
    
    let mut column_indexes = rowrep.iter().enumerate();
    let mut row_indexes_rev = colrep.iter().enumerate();

    column_indexes.all(|(k, &l)| { input[k][l] >= val }) &&
        row_indexes_rev.all(|(l, &k)| { input[k][l] <= val })
}