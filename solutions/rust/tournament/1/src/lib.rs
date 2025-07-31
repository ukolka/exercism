use std::collections::HashMap;
use std::cmp::Ordering;

#[derive(PartialEq, Eq)]
enum Outcome {
    Win = 3,
    Draw = 1,
    Loss = 0,
}

pub fn tally(input: &str) -> String {
    let mut map = HashMap::new();
    for line in input.lines() {
        let mut fields = line.split(';');
        let team1 = fields.next().unwrap();
        let team2 = fields.next().unwrap();
        let result = fields.next().unwrap();
        let team1outcome = parse_outcome(result).unwrap();
        let team2outcome = opposite_outcome(&team1outcome);

        {
            let mut team1stats = map.entry(team1)
                .or_insert(Team::new(team1.to_string()));
            team1stats.game(team1outcome);
        }

        {
            let mut team2stats = map.entry(team2)
                .or_insert(Team::new(team2.to_string()));
            team2stats.game(team2outcome);
        }
    }

    let mut output = Vec::with_capacity(map.len());
    output.push("Team                           | MP |  W |  D |  L |  P".to_string());

    let mut teams = map.values()
        .collect::<Vec<&Team>>();
    teams.sort_unstable_by(|a, b| match b.points.cmp(&a.points) {
        Ordering::Equal => a.name.cmp(&b.name),
        Ordering::Less => Ordering::Less,
        Ordering::Greater => Ordering::Greater,
    });
    
    for team in teams.iter() {
        output.push(
            format!(
                "{:31}| {:2} | {:2} | {:2} | {:2} | {:2}",
                team.name,
                team.matches_played,
                team.wins,
                team.draws,
                team.losses,
                team.points
            )
        );
    }
    
    output.join("\n")
}

fn opposite_outcome(outcome: &Outcome) -> Outcome {
    match outcome {
        &Outcome::Win => Outcome::Loss,
        &Outcome::Loss => Outcome::Win,
        &Outcome::Draw => Outcome::Draw,
    }
}

fn parse_outcome(input: &str) -> Option<Outcome> {
    match input {
        "win" => Some(Outcome::Win),
        "draw" => Some(Outcome::Draw),
        "loss" => Some(Outcome::Loss),
        _ => None
    }
}

struct Team {
    name: String,
    matches_played: u8,
    wins: u8,
    draws: u8,
    losses: u8,
    points: u8,
}

impl Team {
    pub fn new(name: String) -> Self {
        Self {
            name: name,
            matches_played: 0,
            wins: 0,
            draws: 0,
            losses: 0,
            points: 0,
        }
    }

    pub fn game(&mut self, outcome: Outcome) {
        self.matches_played += 1;
        self.wins += if outcome == Outcome::Win { 1 } else { 0 };
        self.draws += if outcome == Outcome::Draw { 1 } else { 0 };
        self.losses += if outcome == Outcome::Loss { 1 } else { 0 };
        self.points += outcome as u8;
    }
}