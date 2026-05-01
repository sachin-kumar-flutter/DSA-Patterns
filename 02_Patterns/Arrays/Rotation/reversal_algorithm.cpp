/*
-------------------------------------
🧩 Problem: Rotate Array by D Positions
📂 Category: Arrays (Pattern - Rotation)
🧠 Concept: Reversal Algorithm

⚡ Approach:
- Normalize d using d % n
- Reverse first d elements
- Reverse remaining n-d elements
- Reverse entire array

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Rotation can be achieved using 3 reversals

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;

        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};
