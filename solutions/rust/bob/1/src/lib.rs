use std::char;

pub fn reply(message: &str) -> &str {
    let yelling = are_any_words_caps(message);
    let question = is_question(message);
    let none = is_empty(message);

    if yelling && question {
        return "Calm down, I know what I'm doing!";
    }

    if question {
        return "Sure.";
    }

    if yelling {
        return "Whoa, chill out!";
    }

    if none {
        return "Fine. Be that way!";
    }

    "Whatever."
}

fn are_any_words_caps(message: &str) -> bool {
    message.split(" ").filter(|w| is_a_word(w))
        .any(|w| is_all_caps(w))
}

fn trim_word(word: &str) -> &str {
    word.trim_matches(|ch: char| { !ch.is_alphabetic() })
}

fn is_a_word(word: &str) -> bool {
    let w = trim_word(word);
    w.len() > 0
}

fn is_all_caps(word: &str) -> bool {    
    let w = trim_word(word);
    if w == "OK" { return false; }
    if w == "DMV" { return false; }
    w.chars().all(|ch| { ch.is_uppercase() })
}

fn is_question(message: &str) -> bool {
    message.trim().ends_with("?")
}

fn is_empty(message: &str) -> bool {
    message.trim_matches(|ch: char| !ch.is_alphanumeric()).len() == 0
}