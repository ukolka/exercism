pub fn find(haystack: &[u32], needle: u32) -> Option<usize> {
    do_find(haystack, (0..haystack.len()).collect::<Vec<usize>>(), needle)
}

fn do_find(haystack: &[u32], indexes: Vec<usize>, needle: u32) -> Option<usize> {
    let len = haystack.len();
    if len == 0 {
        return None;
    }

    if len == 1 {
        if needle == haystack[0] {
            return Some(indexes[0]);
        }
        return None;
    }

    let (left, right) = haystack.split_at(len / 2);
    let (left_idxs, right_idxs) = indexes.split_at(len / 2);
    
    if needle < right[0] {
        return do_find(left, left_idxs.to_vec(), needle);
    }

    do_find(right, right_idxs.to_vec(), needle)
}