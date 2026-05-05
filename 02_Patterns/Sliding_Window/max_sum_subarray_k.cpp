/*
-------------------------------------
🧩 Problem: Maximum Sum Subarray of Size K
📂 Category: Sliding Window (Fixed Size)
🧠 Concept: Maintain window sum of size k

⚡ Approach:
- Compute sum of first k elements
- Slide window:
    → add next element
    → remove outgoing element
- Track maximum sum

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Reuse previous window instead of recomputing

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return -1;

        int windowSum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int maxSum = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};
