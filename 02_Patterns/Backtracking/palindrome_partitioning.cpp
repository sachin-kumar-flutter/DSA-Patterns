/*
-------------------------------------
🧩 Problem: Palindrome Partitioning
📂 Category: Backtracking / Recursion
🧠 Concept: Partition string into valid choices

⚡ Approach:
- Start partition from current index
- Try every possible substring
- If substring is palindrome:
    → choose it
    → recurse on remaining string
- Backtrack after recursion

⏱️ Time Complexity: Exponential
💾 Space Complexity: O(n)

🎯 Key Idea:
- Explore all valid palindrome partitions

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;
    vector<string> temp;

    vector<vector<string>> partition(string s) {

        solve(0, s);

        return ans;
    }

    void solve(int idx, string& s) {

        // Valid partition formed
        if(idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < s.size(); i++) {

            string part = s.substr(idx, i - idx + 1);

            // Choose only palindrome substrings
            if(isPalindrome(part)) {

                temp.push_back(part);

                solve(i + 1, s);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
