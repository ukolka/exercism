const NUM_ALLERGEN: usize = 8;

#[derive(PartialEq, Eq, Debug, Copy, Clone)]
pub enum Allergen {
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}

pub struct Allergies {
    allergies: [Option<Allergen>; NUM_ALLERGEN]
}

impl Allergies {   
    pub fn new(score: u32) -> Self {
        let binary = to_binary(score, NUM_ALLERGEN);
        let mask = &binary[binary.len() - NUM_ALLERGEN ..];
        
        Self {
            allergies: [
                if mask[0] == 1 { Some(Allergen::Cats) } else { None },
                if mask[1] == 1 { Some(Allergen::Pollen) } else { None },
                if mask[2] == 1 { Some(Allergen::Chocolate) } else { None },
                if mask[3] == 1 { Some(Allergen::Tomatoes) } else { None },
                if mask[4] == 1 { Some(Allergen::Strawberries) } else { None },
                if mask[5] == 1 { Some(Allergen::Shellfish) } else { None },
                if mask[6] == 1 { Some(Allergen::Peanuts) } else { None },
                if mask[7] == 1 { Some(Allergen::Eggs) } else { None },
            ]
        }
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        self.allergies.iter()
            .any(|allergy| allergy.is_some() && &allergy.unwrap() == allergen)
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        self.allergies.iter()
            .filter_map(|&allergy| allergy)
            .collect::<Vec<Allergen>>()
    }
}

fn to_binary(number: u32, width: usize) -> Vec<u32> {
    let mut binary = convert_parsed(number, 2);
    if binary.len() >= width {
        return binary;
    }
    
    let mut padded = vec![0; 8 - binary.len()];
    padded.append(&mut binary);
    padded
}

fn convert_parsed(number: u32, to_base: u32) -> Vec<u32> {
    let mut n = number;
    let mut rv = vec![];

    while n > 0 {
        rv.push(((n % to_base) + to_base) % to_base);
        n /= to_base;
    }

    rv.into_iter().rev().collect()
}