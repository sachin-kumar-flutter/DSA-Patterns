/*
-------------------------------------
🧩 Problem: Sqrt(x)
📂 Category: Binary Search (Binary Search on Answer)
🧠 Concept: Find largest number whose square <= x

⚡ Approach:
- Search in range [0, x]
- If mid² <= x:
    → mid can be answer
    → try larger value
- Else shrink right half

⏱️ Time Complexity: O(log x)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Binary search on possible answers

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        int left = 0;
        int right = x;

        int ans = 0;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            // Prevent overflow
            if(1LL * mid * mid == x) return mid;
            if(1LL * mid * mid < x) {
                ans = mid;
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
