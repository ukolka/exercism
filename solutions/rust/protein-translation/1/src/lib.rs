const CODON_WIDTH: usize = 3;

pub fn parse<'a>(pairs: Vec<(&'a str, &'a str)>) -> Translator<'a> {
    Translator {
        map: pairs
    }
}

pub struct Translator<'a> {
    map: Vec<(&'a str, &'a str)>,
}

impl<'a> Translator<'a> {
    
    pub fn name_for(&self, seq: &str) -> Result<&str, ()> {
        let found = self.map.iter().find(|entry| entry.0 == seq);
        match found {
            Some(result) => Ok(result.1),
            None => Err(())
        }
    }

    pub fn of_rna(&self, seq: &str) -> Result<Vec<&str>, ()> {        
        let mut codon = String::with_capacity(CODON_WIDTH);
        let mut rv = vec![];
        
        for ch in seq.chars() {
            codon.push(ch);
            
            if codon.len() == CODON_WIDTH {
                let codon_name = self.name_for(codon.as_str())?;
                if codon_name == "stop codon" {
                    return Ok(rv);
                } else {
                    rv.push(codon_name);
                }
                codon.clear();
            }
        }
        Ok(rv)
    }
}