/*
-------------------------------------
🧩 Problem: Trailing Zeroes in Factorial
📂 Category: Maths (Basics)
🧠 Concept: Counting factors of 5

⚡ Approach:
- Trailing zeroes come from factors of 10 = 2 × 5
- Since 2s are abundant, count number of 5s
- Add contributions of:
    → n/5 + n/25 + n/125 + ...

⏱️ Time Complexity: O(log₅ n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Count how many times 5 appears as a factor

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;

        while(n > 0) {
            n /= 5;
            ans += n;
        }

        return ans;
    }
};
