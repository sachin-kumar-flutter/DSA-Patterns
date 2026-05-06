/*
-------------------------------------
🧩 Problem: Find All Anagrams in a String
📂 Category: Sliding Window (Fixed Size)
🧠 Concept: Frequency matching

⚡ Approach:
- Store frequency of pattern string
- Maintain frequency of current window
- Slide window of size k
- Compare frequency arrays

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(26)

🎯 Key Idea:
- Two strings are anagrams if frequencies match

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> need(26, 0), have(26, 0);
        vector<int> ans;

        // Frequency of pattern
        for(char ch : p) {
            need[ch - 'a']++;
        }

        int k = p.size();

        for(int i = 0; i < s.size(); i++) {

            // Add current character
            have[s[i] - 'a']++;

            // Remove out-of-window character
            if(i >= k) {
                have[s[i - k] - 'a']--;
            }

            // Compare frequencies
            if(have == need) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};
