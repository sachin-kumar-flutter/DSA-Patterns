/*
-------------------------------------
🧩 Problem: Maximum Circular Subarray Sum
📂 Category: Arrays (Pattern - Kadane Variant)
🧠 Concept: Kadane + Wrap Around

⚡ Approach:
1. Find normal max subarray sum (Kadane)
2. Find min subarray sum (Kadane variant)
3. Compute total array sum

→ Two cases:
- Normal max subarray (no wrap)
- Circular max = total - min subarray

⚠️ Edge Case:
- If all elements are negative → return normal max

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Max circular subarray = total sum - minimum subarray

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        int total = 0;

        int currMax = arr[0], maxSum = arr[0];
        int currMin = arr[0], minSum = arr[0];

        for(int i = 0; i < arr.size(); i++) {
            total += arr[i];

            // Kadane for max sum
            currMax = max(arr[i], currMax + arr[i]);
            maxSum = max(maxSum, currMax);

            // Kadane for min sum
            currMin = min(arr[i], currMin + arr[i]);
            minSum = min(minSum, currMin);
        }

        // If all elements are negative
        if(total == minSum) return maxSum;

        // Return best of both cases
        return max(maxSum, total - minSum);
    }
};
