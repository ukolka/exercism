pub fn find<C, T>(haystack: C, needle: T) -> Option<usize>
    where C: AsRef<[T]>,
          T: PartialEq + PartialOrd + Clone
{
    do_find(&haystack, (0..haystack.as_ref().len()).collect::<Vec<usize>>(), needle)
}

fn do_find<C, T>(haystack: C, indexes: Vec<usize>, needle: T) -> Option<usize>
    where C: AsRef<[T]>,
          T: PartialEq + PartialOrd + Clone
{
    let h = haystack.as_ref();
    let len = h.len();
    if len == 0 {
        return None;
    }

    if len == 1 {
        if needle == h[0] {
            return Some(indexes[0]);
        }
        return None;
    }

    let (left, right) = h.split_at(len / 2);
    let (left_idxs, right_idxs) = indexes.split_at(len / 2);
    
    if needle < right[0] {
        return do_find(left, left_idxs.to_vec(), needle);
    }

    do_find(right, right_idxs.to_vec(), needle)
}