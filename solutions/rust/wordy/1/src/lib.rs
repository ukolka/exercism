pub struct WordProblem {
    command: String,
}

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
enum Op {
    Add,
    Subtract,
    Multiply,
    Divide,
}

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
enum Token {
    Operand(i64),
    Operator(Op),
}

impl WordProblem {
    // command: "What is -1 plus -10?"
    pub fn new(command: &str) -> Self {
        Self {
            command: command.to_string(),
        }
    }

    pub fn answer(&self) -> Result<i64, ()> {
        let rpn = self.to_rpn()?;
        let mut result_stack: Vec<i64> = vec![];

        rpn.iter().for_each(|&token|
            match token {
                Token::Operator(Op::Add) => {
                    let operand2 = result_stack[0];
                    let operand1 = result_stack[1];
                    result_stack = result_stack[2..].to_vec();
                    result_stack.insert(0, operand1 + operand2);
                },
                Token::Operator(Op::Subtract) => {
                    let operand2 = result_stack[0];
                    let operand1 = result_stack[1];
                    result_stack = result_stack[2..].to_vec();
                    result_stack.insert(0, operand1 - operand2);
                },
                Token::Operator(Op::Multiply) => {
                    let operand2 = result_stack[0];
                    let operand1 = result_stack[1];
                    result_stack = result_stack[2..].to_vec();
                    result_stack.insert(0, operand1 * operand2);
                }
                Token::Operator(Op::Divide) => {
                    let operand2 = result_stack[0];
                    let operand1 = result_stack[1];
                    result_stack = result_stack[2..].to_vec();
                    result_stack.insert(0, operand1 / operand2);

                },
                Token::Operand(val) => result_stack.insert(0, val),
            });

        Ok(result_stack[0])
    }

    fn to_rpn(&self) -> Result<Vec<Token>, ()> {
        let mut parse_string = self.command.replace("What is ", "");
        parse_string = parse_string.replace(" by", "");
        parse_string = parse_string.replace("?", "");

        let mut rpn_output: Vec<Token> = vec![];
        let mut op_stack: Vec<Op> = vec![];

        for lexeme in parse_string.split_whitespace() {
            let token_candidate = lexeme.parse::<i64>();

            if token_candidate.is_ok() {
                rpn_output.push(Token::Operand(token_candidate.unwrap()));
            } else {
                let op = self.parse_op(lexeme)?;
                
                if op_stack.len() > 0 {
                    let prev_op = op_stack[0];

                    if self.precedence(op) == self.precedence(prev_op) {
                        op_stack = op_stack[1..].to_vec();
                        rpn_output.push(Token::Operator(prev_op));
                    }
                }
                
                op_stack.insert(0, op);
            }
        }

        op_stack.iter().for_each(|&op| rpn_output.push(Token::Operator(op)));
        Ok(rpn_output)
    }
    

    fn parse_op(&self, input: &str) -> Result<Op, ()> {
        match input {
            "plus" => Ok(Op::Add),
            "minus" => Ok(Op::Subtract),
            "multiplied" => Ok(Op::Multiply),
            "divided" => Ok(Op::Divide),
            _ => Err(())
        }
    }

    fn precedence(&self, op: Op) -> u8 {
        match op {
            Op::Add => 1,
            Op::Subtract => 1,
            Op::Multiply => 10,
            Op::Divide => 10,
        }
    }
}

#[test]
fn addition_and_multiplication() {
    let command = "What is 3 minus 4 multiplied by 5?";
    assert_eq!(Ok(-17), WordProblem::new(command).answer());
}