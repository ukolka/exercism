use std::char;

pub fn annotate(board: &[&str]) -> Vec<String> {
    if board.len() == 0 {
        return vec![];
    }

    if board[0].len() == 0 {
        return vec!["".to_string()];
    }

    let lookup = convert(board);
    let mut rv = vec![];
    
    for (i, row) in board.iter().enumerate() {
        rv.push(vec![]);
        for (j, ch) in row.chars().enumerate() {            
            if ch == '*' {
                rv[i].push(ch);
            } else {
                let count = count_mines(&lookup, i, j);
                if count > 0 {
                    rv[i].push(
                        char::from_digit(count as u32, 10).unwrap_or(ch));
                } else {
                    rv[i].push(ch);
                }
            }
        }
    }
    

    rv.into_iter()
        .map(|row| row.iter().collect::<String>())
        .collect::<Vec<String>>()
}

fn count_mines(lookup: &Vec<Vec<char>>, i: usize, j: usize) -> u8 {
    let mut sum = 0;
    for k in i.saturating_sub(1)..(i + 2) {
        for l in j.saturating_sub(1)..(j + 2) {
            if (k == i && l == j) || k >= lookup.len() || l >= lookup[k].len() {
                continue;
            }

            if lookup[k][l] == '*' {
                sum += 1;
            }
        }
    }
    sum
}

fn convert(board: &[&str]) -> Vec<Vec<char>> {
    let mut rv = vec![];
    let mut row_idx = 0;
    
    for line in board.iter() {
        rv.push(vec![]);
        
        for ch in line.chars() {
            rv[row_idx].push(ch);
        }
        row_idx += 1;
    }

    rv
}