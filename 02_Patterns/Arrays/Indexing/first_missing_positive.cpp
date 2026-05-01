/*
-------------------------------------
🧩 Problem: First Missing Positive
📂 Category: Arrays (Pattern - Index Marking / In-place Hashing)
🧠 Concept: Use array indices as hash to mark presence

⚡ Approach:
1. Replace all invalid numbers (<=0 or >n) with n+1
2. Use index marking:
   → For each value x, mark index (x-1) as negative
3. First positive index i → missing number = i+1
4. If all are marked → return n+1

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Use array itself as a hash map by marking indices

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Normalize values
        for(int i = 0; i < n; i++) {
            if(arr[i] <= 0 || arr[i] > n) {
                arr[i] = n + 1;
            }
        }

        // Step 2: Mark indices
        for(int i = 0; i < n; i++) {
            int x = abs(arr[i]);
            if(x >= 1 && x <= n) {
                arr[x - 1] = -abs(arr[x - 1]);
            }
        }

        // Step 3: Find first positive index
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                return i + 1;
            }
        }

        // Step 4: All present
        return n + 1;
    }
};
