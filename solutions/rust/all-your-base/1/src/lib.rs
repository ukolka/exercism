///
/// Convert a number between two bases.
///
/// A number is any slice of digits.
/// A digit is any unsigned integer (e.g. u8, u16, u32, u64, or usize).
/// Bases are specified as unsigned integers.
///
/// Return an `Err(.)` if the conversion is impossible.
/// The tests do not test for specific values inside the `Err(.)`.
///
///
/// You are allowed to change the function signature as long as all test still pass.
///
///
/// Example:
/// Input
///   number: &[4, 2]
///   from_base: 10
///   to_base: 2
/// Result
///   Ok(vec![1, 0, 1, 0, 1, 0])
///
/// The example corresponds to converting the number 42 from decimal
/// which is equivalent to 101010 in binary.
///
///
/// Notes:
///  * The empty slice ( "[]" ) is equal to the number 0.
///  * Never output leading 0 digits. However, your function must be able to
///     process input with leading 0 digits.
///
pub fn convert(number: &[u32], from_base: u32, to_base: u32) -> Result<Vec<u32>, ()> {
    if from_base < 2 || to_base < 2 {
        return Err(());
    }
    
    let mut n = parse(number, from_base)?;
    let mut rv = vec![];

    while n > 0 {
        rv.push(modulus(n, to_base));
        n /= to_base;
    }

    Ok(rv.into_iter().rev().collect())
}

fn parse(number: &[u32], base: u32) -> Result<u32, ()> {
    let mut acc = 0;
    for (idx, digit) in number.iter().rev().enumerate() {
        if digit >= &base {
            return Err(());
        }
        acc += digit * base.pow(idx as u32);
    }
    Ok(acc)
}

fn modulus(a: u32, b: u32) -> u32 {
    ((a % b) + b) % b
}

#[test]
fn test_parse() {
    assert_eq!(parse(&[1, 2, 3], 10), Ok(123));
    assert_eq!(parse(&[0, 1, 0, 1], 2), Ok(5));
    assert_eq!(parse(&[1, 2, 0, 0], 3), Ok(45));
}

#[test]
fn parse_42_in_binary() {
    assert_eq!(parse(&[1, 0, 1, 0, 1, 0], 2), Ok(42));
}