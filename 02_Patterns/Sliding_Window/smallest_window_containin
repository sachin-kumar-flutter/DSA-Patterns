#include <bits/stdc++.h>
using namespace std;

/*
🔥 Problem: Smallest Window Containing 0, 1 and 2

--------------------------------------------------
🧠 APPROACH (Sliding Window)

We are asked to find the minimum length substring
that contains at least one '0', '1' and '2'.

👉 Key Idea:
Whenever problem says:
"smallest window containing all required characters"
→ Think Sliding Window + Frequency Count

--------------------------------------------------
⚡ Steps:

1. Use two pointers:
   - left → start of window
   - right → end of window

2. Maintain frequency array of size 3:
   freq[0], freq[1], freq[2]

3. Expand window:
   - Move right pointer
   - Update frequency

4. When all 3 characters present:
   (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
   → Valid window found

5. Shrink window from left:
   - Update answer (min length)
   - Reduce freq of s[left]
   - Move left

6. Continue until full string processed

--------------------------------------------------
⏱️ Time Complexity: O(N)
⏱️ Space Complexity: O(1)

--------------------------------------------------
💡 Pattern:
Minimum Window Substring
*/

class Solution {
public:
    int smallestSubstring(string s) {
        int n = s.length();
        vector<int> freq(3, 0);

        int left = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            freq[s[right] - '0']++;

            // shrink when valid
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans = min(ans, right - left + 1);

                freq[s[left] - '0']--;
                left++;
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
