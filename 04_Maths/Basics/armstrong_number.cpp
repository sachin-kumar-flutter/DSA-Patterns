/*
-------------------------------------
🧩 Problem: Armstrong Number
📂 Category: Maths (Basics)
🧠 Concept: Digit extraction + exponentiation

⚡ Approach:
1. Count number of digits (k)
2. Extract each digit using %10
3. Add (digit^k) to sum
4. Compare sum with original number

⏱️ Time Complexity: O(d * log k)   (d = digits)
💾 Space Complexity: O(1)

🎯 Key Idea:
- A number is Armstrong if:
  sum of (each digit ^ total digits) = number

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        int original = n;

        // Step 1: count digits
        int digits = 0;
        int temp = n;
        while(temp > 0) {
            digits++;
            temp /= 10;
        }

        // Edge case: n = 0
        if(n == 0) digits = 1;

        // Step 2: compute sum
        int sum = 0;
        temp = n;

        while(temp > 0) {
            int digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }

        return sum == original;
    }
};
