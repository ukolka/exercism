pub fn is_armstrong_number(num: u32) -> bool {
    let mut n = num;
    let mut digits = Vec::with_capacity(10);
    while n > 0 {
        digits.push(n % 10);
        n /= 10;
    }

    let mut sum = 0;
    let digit_num = digits.len() as u32;
    for digit in &digits {
        sum += digit.pow(digit_num);
    }

    return sum == num;
}