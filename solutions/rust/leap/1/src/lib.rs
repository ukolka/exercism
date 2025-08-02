pub fn is_leap_year(year: i32) -> bool {
    let divisible_by_4 = year % 4 == 0;
    let divisible_by_100 = year % 100 == 0;
    let divisible_by_400 = year % 400 == 0;

    if divisible_by_4 && divisible_by_400 {
        true
    } else if divisible_by_4 && divisible_by_100 {
        false
    } else {
        divisible_by_4
    }
}