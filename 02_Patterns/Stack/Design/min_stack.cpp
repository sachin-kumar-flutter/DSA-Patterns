/*
-------------------------------------
🧩 Problem: Min Stack
📂 Category: Stack / Design
🧠 Concept:
- Auxiliary stack
- Constant-time minimum retrieval

⚡ Approach:
- Main stack stores elements
- Min stack stores minimum value
  up to each position
- Top of min stack always gives
  current minimum

⏱️ Time Complexity:
    push()   -> O(1)
    pop()    -> O(1)
    peek()   -> O(1)
    getMin() -> O(1)

💾 Space Complexity: O(n)

🎯 Key Idea:
- Track running minimum alongside
  normal stack operations

-------------------------------------
*/

class SpecialStack {
public:

    stack<int> mainStack;
    stack<int> minStack;

    SpecialStack() {}

    // Insert element
    void push(int value) {
      
        if(mainStack.empty()) minStack.push(value);
        else minStack.push(min(minStack.top(), value));
        mainStack.push(value);
    }

    // Remove top element
    void pop() {
        mainStack.pop();
        minStack.pop();
    }

    // Return top element
    int peek() return mainStack.top();

    // Check if stack is empty
    bool isEmpty() return mainStack.empty();
    // Return minimum element
    int getMin() return minStack.top();
};
