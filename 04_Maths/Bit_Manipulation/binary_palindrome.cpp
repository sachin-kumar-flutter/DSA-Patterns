/*
-------------------------------------
🧩 Problem: Binary Palindrome
📂 Category: Maths (Bit Manipulation)
🧠 Concept: Binary representation + Two pointers

⚡ Approach:
- Convert number to binary string
- Check if the binary string is a palindrome

⏱️ Time Complexity: O(log n)
💾 Space Complexity: O(log n)

🎯 Key Idea:
- A number is binary palindrome if its binary form is symmetric

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(long long int N) {

        string s;

        // Convert to binary
        while(N > 0) {
            s += (N % 2) + '0';
            N /= 2;
        }

        // Edge case: N = 0
        if(s.empty()) s = "0";

        // Check palindrome
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++, j--;
        }

        return true;
    }
};
