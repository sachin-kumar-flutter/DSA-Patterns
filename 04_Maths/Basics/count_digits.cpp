/*
-------------------------------------
🧩 Problem: Count Digits in a Number
📂 Category: Maths (Basics)
🧠 Concept: Division by 10

⚡ Approach:
- Repeatedly divide number by 10
- Count how many times until it becomes 0

⏱️ Time Complexity: O(log₁₀ n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Each division removes one digit

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        if(n == 0) return 1; // edge case

        int count = 0;

        while(n > 0) {
            count++;
            n /= 10;
        }

        return count;
    }
};
