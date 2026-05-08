/*
-------------------------------------
🧩 Problem: Aggressive Cows
📂 Category: Binary Search (Binary Search on Answer)
🧠 Concept: Maximize minimum distance

⚡ Approach:
- Sort stall positions
- Binary search minimum distance
- Check if k cows can be placed
  with at least that distance

⏱️ Time Complexity: O(n log(range))
💾 Space Complexity: O(1)

🎯 Key Idea:
- Binary search on feasible distance

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(), stalls.end());

        int left = 1;
        int right = stalls.back() - stalls[0];

        int ans = 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(isPossible(stalls, k, mid)) {
                ans = mid;
                left = mid + 1; // try larger distance
            }

            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    bool isPossible(vector<int> &stalls, int k, int minDistance) {

        int cows = 1;
        int lastPlaced = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {

            if(stalls[i] - lastPlaced >= minDistance) {
                cows++;
                lastPlaced = stalls[i];
            }
        }

        return cows >= k;
    }
};
