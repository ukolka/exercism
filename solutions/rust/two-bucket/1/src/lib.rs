#[derive(PartialEq, Eq, Debug, Clone)]
pub enum Bucket {
    One,
    Two
}

/// A struct to hold your results in.
#[derive(PartialEq, Eq, Debug)]
pub struct BucketStats {
    /// The total number of "moves" it should take to reach the desired number of liters, including
    /// the first fill.
    pub moves: u8,
    /// Which bucket should end up with the desired number of liters? (Either "one" or "two")
    pub goal_bucket: Bucket,
    /// How many liters are left in the other bucket?
    pub other_bucket: u8,
}

/// Solve the bucket problem
pub fn solve(capacity_1: u8,
             capacity_2: u8,
             goal: u8,
             start_bucket: &Bucket) -> BucketStats
{
    let start = match start_bucket {
        &Bucket::One => (capacity_1, 0),
        &Bucket::Two => (0, capacity_2),
    };
    
    let solution_opt = billiards(capacity_1, capacity_2, start, goal);
    
    let solution = solution_opt.unwrap();
    
    let goal_bucket = if (solution.0).0 == goal {
        Bucket::One } else { Bucket::Two };
    
    let other_bucket = match goal_bucket {
        Bucket::One => (solution.0).1,
        Bucket::Two => (solution.0).0,
    };
    
    BucketStats {
        moves: solution.1,
        goal_bucket: goal_bucket,
        other_bucket: other_bucket,
    }
}

macro_rules! check_and_return {
    ($test:ident, $goal:ident, $start:ident, $moves:ident) => {
        {
            if is_solution($test, $goal) {
                return Some(($test, $moves));
            }
        }    
    }
}

fn billiards(x: u8, y: u8, start: (u8, u8), goal: u8) -> Option<((u8, u8), u8)> {
    let mut test = start;
    let mut moves = 1;
    
    while !is_solution(test, goal) {
        if test.1 == 0 || test.0 == x {
            while test.0 > 0 && test.1 < y {
                test.0 -= 1;
                test.1 += 1;
            }
            moves += 1;
        }

        check_and_return!(test, goal, start, moves);
        
        if test.1 == y {
            test.1 = 0;
            moves += 1;
        }

        check_and_return!(test, goal, start, moves);
        
        if test.0 == 0 {
            test.0 = x;
            moves += 1;
        }

        check_and_return!(test, goal, start, moves);
        if test == start {
            return None;
        }
    }

    None
}

fn is_solution(position: (u8, u8), goal: u8) -> bool {
    position.0 == goal || position.1 == goal
}