/*
-------------------------------------
🧩 Problem: Maximum Subarray Sum
📂 Category: Arrays (Pattern - Kadane’s Algorithm)
🧠 Concept: Greedy / Dynamic Programming

⚡ Approach:
- Maintain current sum (curr) and maximum sum (ans)
- At each index:
    → Either start fresh from current element
    → Or extend previous subarray
- Take maximum at each step

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- At each step, decide:
  “Start new subarray OR extend previous one”

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int curr = arr[0];
        int ans = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);
            ans = max(ans, curr);
        }

        return ans;
    }
};
