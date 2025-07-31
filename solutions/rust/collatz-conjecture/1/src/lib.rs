// return Ok(x) where x is the number of steps required to reach 1
pub fn collatz(n: u64) -> Result<u64, &'static str> {
    match n {
        0 => Err("Invalid n"),
        1 => Ok(0),
        _ => if n % 2 == 0 {
            Ok(1 + collatz(n / 2).unwrap())
        } else {
            Ok(1 + collatz((n * 3) + 1).unwrap())
        },
    }
}