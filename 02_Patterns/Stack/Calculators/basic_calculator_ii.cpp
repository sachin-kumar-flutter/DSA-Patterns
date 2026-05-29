/*
-------------------------------------
🧩 Problem: Basic Calculator II
📂 Category: Stack / Expression Evaluation
🧠 Concept:
- Operator precedence
- Stack simulation

⚡ Approach:
- Build numbers digit-by-digit
- Process previous operator when a new
  operator is encountered
- Store results in stack
- Handle * and / immediately
- Sum stack at the end

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Use stack to preserve precedence
  without building an expression tree

-------------------------------------
*/

class Solution {
public:

    int calculate(string expression) {
        stack<int> valueStack;
        char previousOperator = '+';
        int currentNumber = 0;
        for(int i = 0; i < expression.size(); i++) {

            char currentChar = expression[i];
            // Build multi-digit number
            if(isdigit(currentChar)) {
                currentNumber = currentNumber * 10 + (currentChar - '0');
            }
            // Process previous operator
            if((!isdigit(currentChar) && currentChar != ' ') || i == expression.size() - 1) {

                if(previousOperator == '+') valueStack.push(currentNumber);
                else if(previousOperator == '-') valueStack.push(-currentNumber);

                else if(previousOperator == '*') {

                    int topValue = valueStack.top();
                    valueStack.pop();
                    valueStack.push(topValue * currentNumber);
                }
                else if(previousOperator == '/') {
                    int topValue = valueStack.top();
                    valueStack.pop();
                    valueStack.push(topValue / currentNumber);
                }

                previousOperator = currentChar;
                currentNumber = 0;
            }
        }

        int answer = 0;
        while(!valueStack.empty()) {

            answer += valueStack.top();
            valueStack.pop();
        }

        return answer;
    }
};
