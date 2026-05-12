/*
-------------------------------------
🧩 Problem: Phone Keypad Combinations
📂 Category: Backtracking / Recursion
🧠 Concept: Generate combinations from choices

⚡ Approach:
- Each digit maps to multiple characters
- Choose one character at current index
- Recurse for next digit
- Backtrack after recursion

⏱️ Time Complexity: O(4^n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Every digit expands into multiple choices

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<string> ans;

    vector<string> phone = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    string current;

    vector<string> possibleWords(vector<int> &arr) {

        solve(0, arr);

        return ans;
    }

    void solve(int idx, vector<int> &arr) {

        // Complete combination formed
        if(idx == arr.size()) {
            ans.push_back(current);
            return;
        }

        string letters = phone[arr[idx]];

        // Skip invalid mappings
        if(letters == "") {
            solve(idx + 1, arr);
            return;
        }

        for(char ch : letters) {

            current.push_back(ch);

            solve(idx + 1, arr);

            // Backtrack
            current.pop_back();
        }
    }
};
