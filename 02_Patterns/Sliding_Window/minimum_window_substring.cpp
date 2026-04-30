#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Sliding Window + HashMap
        // Goal: Find the minimum window in 's' that contains all characters of 't'

        unordered_map<char, int> freq;

        // Store frequency of characters in t
        for (char ch : t) {
            freq[ch]++;
        }

        int start = 0, end = 0;
        int required = t.size();   // total characters needed
        int minLen = INT_MAX;
        int startIndex = -1;

        while (end < s.size()) {
            // Include current character into window
            freq[s[end]]--;

            // If character was needed, reduce required count
            if (freq[s[end]] >= 0) {
                required--;
            }

            // When all characters are matched
            while (required == 0) {

                // Update minimum window
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    startIndex = start;
                }

                // Remove left character from window
                freq[s[start]]++;

                // If this character was required, window becomes invalid
                if (freq[s[start]] > 0) {
                    required++;
                }

                start++;
            }

            end++;
        }

        // If no valid window found
        if (minLen == INT_MAX) return "";

        return s.substr(startIndex, minLen);
    }
};
