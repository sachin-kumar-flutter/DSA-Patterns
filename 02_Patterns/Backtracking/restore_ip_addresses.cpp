/*
-------------------------------------
🧩 Problem: Restore IP Addresses
📂 Category: Backtracking / Recursion
🧠 Concept: Partition string with validation

⚡ Approach:
- Split string into 4 valid parts
- Each part must:
    → be between 0 and 255
    → not contain leading zeros
- Backtrack after exploring each segment

⏱️ Time Complexity: Exponential
💾 Space Complexity: O(1)

🎯 Key Idea:
- Recursive partitioning with constraints

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<string> ans;
    vector<string> path;

    vector<string> generateIp(string &s) {

        solve(0, s);

        return ans;
    }

    void solve(int idx, string &s) {

        // Valid IP formed
        if(idx == s.size() && path.size() == 4) {

            ans.push_back(
                path[0] + '.' +
                path[1] + '.' +
                path[2] + '.' +
                path[3]
            );

            return;
        }

        // Too many segments
        if(path.size() > 4) {
            return;
        }

        // Try segment lengths 1 to 3
        for(int len = 1; len <= 3; len++) {

            if(idx + len > s.size()) {
                break;
            }

            string segment = s.substr(idx, len);

            if(isValid(segment)) {

                path.push_back(segment);

                solve(idx + len, s);

                // Backtrack
                path.pop_back();
            }
        }
    }

    bool isValid(string s) {

        // Leading zeros not allowed
        if(s.size() > 1 && s[0] == '0') {
            return false;
        }

        int value = stoi(s);

        return value >= 0 && value <= 255;
    }
};
