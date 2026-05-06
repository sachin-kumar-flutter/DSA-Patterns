/*
-------------------------------------
🧩 Problem: Longest Repeating Character Replacement
📂 Category: Sliding Window (Variable Size)
🧠 Concept: Maintain max frequency in window

⚡ Approach:
- Expand window using right pointer
- Track frequency of characters
- Keep track of max frequency in window
- If window size - maxFreq > k → shrink window
- Update max length

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(26)

🎯 Key Idea:
- Only care about most frequent character

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0, maxFreq = 0, ans = 0;

        for(int right = 0; right < s.size(); right++) {

            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Shrink if invalid
            while((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
