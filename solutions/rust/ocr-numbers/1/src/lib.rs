// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[allow(unused_variables)]
pub fn convert(input: &str) -> Result<String, ()> {
    let mut candidates = vec![vec![]];
    let mut line_idx = 0;
    let mut col_idx = 0;
    let mut cs_idx = 0;
    
    for ch in input.chars() {
        if line_idx == 3 && ch == '\n' {
            candidates.push(vec![]);
            line_idx = 0;
            col_idx = 0;
            cs_idx += 1;
            continue;
        }
        
        if line_idx == 0 && col_idx % 3 == 0 {
            candidates[cs_idx].push("".to_string());
        }
        
        if ch == '\n' {
            col_idx = 0;
            if col_idx % 3 == 0 {
                
                line_idx += 1;
            } else {
                return Err(())
            }
            continue;
        }

        candidates[cs_idx][col_idx / 3].push(ch);
        
        col_idx += 1;
    }

    if col_idx % 3 == 0 {
        line_idx += 1;
    } else {
        return Err(())
    }
    
    if line_idx % 4 > 0 {
        return Err(());
    }

    let mut rv = "".to_string();
    for candidate_line in candidates.into_iter() {
        for candidate in candidate_line.into_iter() {
            if candidate.len() == 12 {
                rv.push(translate(candidate));
            }
        }
        rv.push(',');
    }
    rv.pop();
    Ok(rv)
}

fn translate(candidate: String) -> char {
    match candidate.as_str() {
        " _ | ||_|   " => '0',
        "     |  |   " => '1',
        " _  _||_    " => '2',
        " _  _| _|   " => '3',
        "   |_|  |   " => '4',
        " _ |_  _|   " => '5',
        " _ |_ |_|   " => '6',
        " _   |  |   " => '7',
        " _ |_||_|   " => '8',
        " _ |_| _|   " => '9',
        _ => '?',
    }
}