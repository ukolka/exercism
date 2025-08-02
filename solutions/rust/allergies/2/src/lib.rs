#[derive(PartialEq, Eq, Debug, Copy, Clone)]
pub enum Allergen {
    Eggs = 1,
    Peanuts = 2,
    Shellfish = 4,
    Strawberries = 8,
    Tomatoes = 16,
    Chocolate = 32,
    Pollen = 64,
    Cats = 128,
}

pub struct Allergies(u8);

impl Allergies {   
    pub fn new(score: u32) -> Self {        
        Allergies(score as u8)
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        self.0 & (*allergen as u8) != 0
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        vec![
            Allergen::Eggs,
            Allergen::Peanuts,
            Allergen::Shellfish,
            Allergen::Strawberries,
            Allergen::Tomatoes,
            Allergen::Chocolate,
            Allergen::Pollen,
            Allergen::Cats
        ].iter()
            .filter(|allergen| self.is_allergic_to(allergen))
            .map(|&allergen| allergen)
            .collect::<Vec<Allergen>>()
    }
}