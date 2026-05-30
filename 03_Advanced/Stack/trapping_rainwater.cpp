/*
-------------------------------------
🧩 Problem: Trapping Rain Water
📂 Category: Stack / Histogram Problems
🧠 Concept:
- Monotonic decreasing stack
- Boundary detection

⚡ Approach:
- Maintain decreasing heights
- When a taller bar appears:
    a valley is discovered
- Calculate trapped water using:
    width × bounded height

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Water is trapped between
  left and right boundaries

-------------------------------------
*/

class Solution {
public:

    int trap(vector<int>& height) {

        stack<int> indexStack;
        int totalWater = 0;

        for(int currentIndex = 0; currentIndex < height.size(); currentIndex++) {

            while(!indexStack.empty() && height[currentIndex] > height[indexStack.top()]) {

                int valleyIndex = indexStack.top();
                indexStack.pop();

                // No left boundary
                if(indexStack.empty()) break;
                int leftBoundary = indexStack.top();
                int rightBoundary = currentIndex;
              
                int boundedHeight = min(height[leftBoundary], height[rightBoundary]) - height[valleyIndex];
                int width = rightBoundary - leftBoundary - 1;
                totalWater += width * boundedHeight;
            }

            indexStack.push(currentIndex);
        }

        return totalWater;
    }
};
