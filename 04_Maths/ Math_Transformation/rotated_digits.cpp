/*
-------------------------------------
🧩 Problem: Rotated Digits
📂 Category: Math (Pattern - Digit Manipulation)
🧠 Concept: Digit Validation + Simulation

⚡ Approach:
- Iterate from 1 to n
- For each number:
    → Check if it becomes a valid and different number after rotation
- Rules:
    → Invalid digits: 3, 4, 7
    → Valid but same: 0, 1, 8
    → Valid and different: 2, 5, 6, 9

⏱️ Time Complexity: O(n * digits)
💾 Space Complexity: O(1)

🎯 Key Idea:
- A number is "good" if:
  → It contains at least one changing digit
  → And no invalid digits

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            if(isGood(i)) ans++;
        }

        return ans;
    }

    bool isGood(int x) {
        bool changed = false;

        while(x > 0) {
            int digit = x % 10;
            x /= 10;

            // Invalid digits
            if(digit == 3 || digit == 4 || digit == 7) return false;

            // Digits that change after rotation
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                changed = true;
            }
        }

        return changed;
    }
};
