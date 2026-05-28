/*
-------------------------------------
🧩 Problem: Daily Temperatures
📂 Category: Stack / Monotonic Stack
🧠 Concept: Next greater element pattern

⚡ Approach:
- Maintain decreasing temperature stack
- Current warmer temperature resolves
  previous colder days
- Store indices inside stack

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Monotonic stack efficiently tracks unresolved days

-------------------------------------
*/

class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> indexStack;

        for(int currentDay = 0; currentDay < n; currentDay++) {

            // Resolve colder previous days
            while(!indexStack.empty() && temperatures[currentDay] > temperatures[indexStack.top()]) {
                int previousDay = indexStack.top();
                indexStack.pop();
                answer[previousDay] = currentDay - previousDay;
            }
            // Store unresolved day
            indexStack.push(currentDay);
        }

        return answer;
    }
};
