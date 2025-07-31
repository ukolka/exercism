mod linked_list;

use linked_list::SimpleLinkedList;

pub struct Brackets {
    balanced: bool
}

impl Brackets {
    pub fn are_balanced(&self) -> bool {
        self.balanced
    }

    fn is_opening(ch: char) -> bool {
        ch == '[' || ch == '(' || ch == '{'
    }

    fn is_closing(ch: char) -> bool {
        ch == ']' || ch == ')' || ch == '}'
    }

    fn is_paired_closing(last_opening: Option<&char>, ch: char) -> bool {
        return match last_opening {
            Some(&'(') => ch == ')',
            Some(&'[') => ch == ']',
            Some(&'{') => ch == '}',
            _ => false,
        };
    }
}

impl<'a> From<&'a str> for Brackets {
    fn from(s: &'a str) -> Self {
        let mut stack = SimpleLinkedList::new();
        let mut balanced = true;
        for ch in s.chars() {
            if Brackets::is_opening(ch) {
                stack.push(ch);
            }

            if Brackets::is_closing(ch) {
                if Brackets::is_paired_closing(stack.peek(), ch) {
                    stack.pop();
                } else {
                    balanced = false;
                    break;
                }
            }
        }
            
        Self {
            balanced: balanced && stack.len() == 0 
        }
    }
}