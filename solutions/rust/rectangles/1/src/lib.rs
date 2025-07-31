pub fn count(input: &[&str]) -> usize {
    let len = input.len();
    if len == 0 {
        return 0;
    }
    
    let mut input_vec: Vec<Vec<char>> = Vec::with_capacity(len);

    let mut line_len = 0; 
    for line in input {
        line_len = line.len();
        if line_len == 0 {
            return 0;
        }
        
        let mut line_vec: Vec<char> = Vec::with_capacity(line_len);
        for ch in line.chars() {            
            line_vec.push(ch);
        }
        input_vec.push(line_vec);
    }
    
    let mut rectangles = 0;
    
    for height in 1..(len + 1) {
        for width in 1..(line_len + 1) {
            rectangles += count_rectangles(&input_vec, width, height);
        }
    }
    
    rectangles
}

fn count_rectangles
    (input: &Vec<Vec<char>>, width: usize, height: usize) ->
    usize
{
        
    let mut count = 0;

    let rows = input.len();    
    for i in 0..rows {
        
        let cols = input[i].len();       
        for j in 0..cols {
            
            if input[i][j] == '+' {
                if (j + width) < cols &&
                    (i + height) < rows &&
                    is_rectangle(input, i, j, width, height)
                {
                    count += 1;
                }
            }
        }
    }

    count
}

fn is_rectangle
    (input: &Vec<Vec<char>>, row: usize, col: usize, width: usize, height: usize) ->
    bool
{
    let last_col = col + width;
    let last_row = row + height;

    for c in (col + 1)..(last_col) {
        match input[row][c] {
            '+' | '-' => {},
            _ => { return false; },
        }

        match input[last_row][c] {
            '+' | '-' => {},
            _ => { return false; },
        }
    }
    
    for r in (row + 1)..(last_row) {
        match input[r][col] {
            '+' | '|' => {},
            _ => { return false; },
        }
        
        match input[r][last_col] {
            '+' | '|' => {},
            _ => { return false; },
        }
    }
    
    if input[row][last_col] != '+' ||
        input[last_row][col] != '+' ||
        input[last_row][last_col] != '+' {
        return false;
    }

    true
}

#[test]
fn test_grid_2() {
    let lines = vec![
       //012
        "+++",//0
        "+++",//1
        "+++",//2
    ];
    assert_eq!(9, count(&lines));
}

#[test]
fn test_grid_3() {
    let lines = vec![
       //0123
        "++++",//0
        "++++",//1
        "++++",//2
        "++++",//3
    ];
    assert_eq!(36, count(&lines));
}