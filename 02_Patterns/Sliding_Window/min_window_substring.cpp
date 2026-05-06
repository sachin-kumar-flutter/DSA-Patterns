/*
-------------------------------------
🧩 Problem: Minimum Window Substring
📂 Category: Sliding Window (Variable Size - Advanced)
🧠 Concept: Track required vs formed characters

⚡ Approach:
- Count frequency of required chars (t)
- Expand window with right pointer
- Track how many characters are fully satisfied (formed)
- When all required are formed:
    → try shrinking from left
- Keep minimum valid window

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(Σ)

🎯 Key Idea:
- Maintain validity using formed == required

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> needed, have;

        for(char ch : t) needed[ch]++;

        int required = needed.size();
        int formed = 0;

        int left = 0, start = 0;
        int minLength = INT_MAX;

        for(int right = 0; right < s.size(); right++) {
            char ch = s[right];
            have[ch]++;

            if(needed.count(ch) && have[ch] == needed[ch]) {
                formed++;
            }

            while(formed == required) {

                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                char a = s[left];
                have[a]--;

                if(needed.count(a) && have[a] < needed[a]) {
                    formed--;
                }

                left++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};
