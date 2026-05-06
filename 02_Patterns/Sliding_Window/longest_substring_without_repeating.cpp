/*
-------------------------------------
🧩 Problem: Longest Substring Without Repeating Characters
📂 Category: Sliding Window (Variable Size)
🧠 Concept: Expand + shrink window with a set

⚡ Approach:
- Use two pointers (left, right)
- Expand right pointer
- If duplicate appears:
    → shrink window from left until valid
- Track maximum window length

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(Σ) (character set)

🎯 Key Idea:
- Maintain a window with all unique characters

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int left = 0, ans = 0;

        for(int right = 0; right < s.size(); right++) {

            // Shrink until no duplicate
            while(seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            // Expand window
            seen.insert(s[right]);

            // Update answer
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
