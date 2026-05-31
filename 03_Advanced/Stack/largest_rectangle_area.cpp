/*
-------------------------------------
🧩 Problem: Largest Rectangle in Histogram
📂 Category: Stack / Histogram Problems
🧠 Concept:
- Monotonic increasing stack
- Previous Smaller Element
- Next Smaller Element

⚡ Approach:
- Maintain increasing stack of indices
- When a smaller bar appears:
    compute rectangles immediately
- Use a virtual height 0 bar
  to flush remaining bars

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Every bar acts as the limiting height
  of a rectangle exactly once

-------------------------------------
*/

class Solution {
public:

    int getMaxArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> indexStack;
        int maximumArea = 0;

        for(int i = 0; i <= n; i++) {

            int currentHeight = (i == n) ? 0 : heights[i];

            while(!indexStack.empty() && currentHeight < heights[indexStack.top()]) {

                int height = heights[indexStack.top()];
                indexStack.pop();
                int width = indexStack.empty() ? i : i - indexStack.top() - 1;
                maximumArea = max(maximumArea, height * width);
            }
            indexStack.push(i);
        }

        return maximumArea;
    }
};
