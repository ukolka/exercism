pub fn map_function<F>(input: Vec<i32>, function: F) -> Vec<i32>
    where
    F: Fn(i32) -> i32
{
    let mut output: Vec<i32> = Vec::with_capacity(input.len());
    for entry in input.into_iter() {
        output.push(function(entry));
    }

    output
    
}

pub fn map_closure<F>(input: Vec<i32>, closure: F) -> Vec<i32>
    where
    F: Fn(i32) -> i32
{
    map_function(input, closure)
}