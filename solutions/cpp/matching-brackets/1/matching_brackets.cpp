#include "matching_brackets.h"
#include <stack>

namespace matching_brackets {
    bool check(const std::string& str) {
        std::stack<char> char_stack{};
        
        for (const auto& ch : str) {
            switch (ch) {
                case ('{'):
                    char_stack.push('}'); break;
                case ('['): 
                    char_stack.push(']'); break;
                case ('('): 
                    char_stack.push(')'); break;
                case ('}'):
                case (']'):
                case (')'):
                    if (char_stack.size() > 0) {
                        if (char_stack.top() == ch) {
                            char_stack.pop();
                        } else {
                            return false;
                        }
                    }
                    break;
            }
        }
        return char_stack.size() == 0;
    }
}  // namespace matching_brackets
