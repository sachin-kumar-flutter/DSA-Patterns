/*
-------------------------------------
🧩 Problem: String to Integer (atoi)
📂 Category: Strings (Pattern - Parsing)
🧠 Concept: Simulation + Edge Case Handling

⚡ Approach:
1. Skip leading whitespaces
2. Check sign (+ / -)
3. Read digits and build number
4. Handle overflow conditions
5. Stop at first non-digit

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Carefully simulate integer conversion with constraints

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string &s) {
        int n = s.size(), i = 0;

        // Step 1: Skip leading spaces
        while(i < n && s[i] == ' ') i++;

        // Step 2: Handle sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        long res = 0;

        // Step 3: Convert digits
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Handle overflow
            if(res > INT_MAX / 10 || 
              (res == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return sign * res;
    }
};
