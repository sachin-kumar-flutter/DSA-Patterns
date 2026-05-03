/*
-------------------------------------
🧩 Problem: Palindrome Number
📂 Category: Maths (Basics)
🧠 Concept: Reverse / Symmetry Check

⚡ Approach (String-based):
- Convert number to string
- Compare characters from both ends
- If mismatch → not palindrome

⏱️ Time Complexity: O(d)
💾 Space Complexity: O(d)

🎯 Key Idea:
- Palindrome reads same forward and backward

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        string s = to_string(abs(n));
        int m = s.size();

        for(int i = 0; i < m / 2; i++) {
            if(s[i] != s[m - i - 1]) {
                return false;
            }
        }

        return true;
    }
};
