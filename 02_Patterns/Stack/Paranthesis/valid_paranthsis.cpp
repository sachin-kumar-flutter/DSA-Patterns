/*
-------------------------------------
🧩 Problem: Valid Parentheses
📂 Category: Stack / Parentheses
🧠 Concept: Balanced bracket matching

⚡ Approach:
- Push opening brackets into stack
- On closing bracket:
    match with stack top
- Invalid if mismatch occurs
- Stack must be empty at end

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Stack naturally handles nested structures

-------------------------------------
*/

class Solution {
public:

    bool isValid(string s) {
        stack<char> bracketStack;

        for(char currentChar : s) {

            // Opening brackets
            if(currentChar == '(' || currentChar == '{' || currentChar == '[') bracketStack.push(currentChar);
            // Closing brackets
            else {

                // No matching opening bracket
                if(bracketStack.empty()) return false;

                char topBracket = bracketStack.top();
                bracketStack.pop();

                // Check matching pair
                if(topBracket == '(' && currentChar != ')') return false;
                else if(topBracket == '{' && currentChar != '}') return false;
                else if(topBracket == '[' && currentChar != ']') return false;
            }
        }

        // Stack should be empty
        return bracketStack.empty();
    }
};
