/*
-------------------------------------
🧩 Problem: Next Greater Element
📂 Category: Stack / Monotonic Stack
🧠 Concept: Monotonic decreasing stack

⚡ Approach:
- Maintain indices inside stack
- Stack stores elements in decreasing order
- Current element resolves answers
  for smaller previous elements

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Stack helps process unresolved elements efficiently

-------------------------------------
*/

class Solution {
public:

    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextGreater(n, -1);
        stack<int> indexStack;

        for(int i = 0; i < n; i++) {
            // Resolve smaller elements
            while(!indexStack.empty() && arr[i] > arr[indexStack.top()]) {
                nextGreater[indexStack.top()] = arr[i];
                indexStack.pop();
            }
            // Store unresolved index
            indexStack.push(i);
        }

        return nextGreater;
    }
};
