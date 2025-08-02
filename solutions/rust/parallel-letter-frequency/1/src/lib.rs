use std::collections::HashMap;
use std::thread;

pub fn frequency(input: &[&str], workers: usize) -> HashMap<char,u32> {
    let len = input.len();
    let mut rv = HashMap::new();
    if len == 0 {
        return rv;
    }
    
    let w = if workers > len { len } else { workers };
    let chunk_size = input.len() / w;

    let mut children = Vec::with_capacity(w);
    
    for i in 0..w {
        let start = i * chunk_size;
        let end = if i == (workers - 1) {
            input.len()
        } else {
            i * chunk_size + chunk_size
        };
        
        let chunk = input[start..end].iter()
            .map(|el| el.to_string()).collect::<Vec<String>>();
        
        children.push(thread::spawn(move || -> HashMap<char,u32> {
            let mut hm = HashMap::new();
            
            for line in chunk.iter() {
                for ch in line.to_lowercase().chars() {
                    match ch {
                        '0' ... '9' | ',' | ' ' | '\t' | '\n' => {
                            continue;
                        },
                        _ => {
                            let counter = hm.entry(ch).or_insert(0);
                            *counter += 1;
                            
                        }
                    }
                }
            }
            
            hm
        }));
    }

    for child in children {
        let intermediate_hm = child.join().unwrap();

        for (&ch, &freq) in &intermediate_hm {
            let counter = rv.entry(ch).or_insert(0);
            *counter += freq;
        }
    }

    rv
}