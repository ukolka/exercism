fn init_result(size: usize) -> Vec<Vec<usize>> {
    let mut result: Vec<Vec<usize>> = Vec::with_capacity(size);
    for i in 0..size {
        result.push(Vec::with_capacity(size));
        for _ in 0..size {
            result[i].push(0);
        }
    }
    result
}

pub fn spiral_matrix(size: usize) -> Vec<Vec<usize>> {
    if size == 0 { return vec![]; }
    if size == 1 { return vec![vec![1]]; }

    let mut result = init_result(size);
    let mut end_column = size;
    let mut end_row = size;
    let mut start_column = 0;
    let mut start_row = 0;

    let mut counter = 1;
    
    while start_column < end_column && start_row < end_row {
        for c in start_column..end_column {
            result[start_row][c] = counter;
            counter += 1;
        }
        start_row += 1;

        for r in start_row..end_row {
            result[r][end_column - 1] = counter;
            counter += 1;
        }
        end_column -= 1;


        for c in (start_column..end_column).rev() {
            result[end_row - 1][c] = counter;
            counter += 1;
        }
        end_row -= 1;

        for r in (start_row..end_row).rev() {
            result[r][start_column] = counter;
            counter += 1;
        }
        start_column += 1;
    }
    
    result
}