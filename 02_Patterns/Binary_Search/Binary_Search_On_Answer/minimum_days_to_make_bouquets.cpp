/*
-------------------------------------
🧩 Problem: Minimum Days to Make M Bouquets
📂 Category: Binary Search (Binary Search on Answer)
🧠 Concept: Minimize feasible days

⚡ Approach:
- Search answer in range:
    [min bloom day, max bloom day]
- Check if m bouquets can be formed
  using adjacent flowers
- Minimize the feasible day

⏱️ Time Complexity: O(n log(maxDay))
💾 Space Complexity: O(1)

🎯 Key Idea:
- Binary search on feasible days

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minDaysBloom(vector<int>& arr, int k, int m) {

        int n = arr.size();

        if(1LL * m * k > n) {
            return -1;
        }

        int left = *min_element(arr.begin(), arr.end());
        int right = *max_element(arr.begin(), arr.end());

        int ans = right;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(isPossible(arr, k, m, mid)) {
                ans = mid;
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(vector<int>& arr, int k, int m, int days) {

        int bouquets = 0;
        int flowers = 0;

        for(int bloomDay : arr) {

            if(bloomDay <= days) {
                flowers++;
            }

            else {
                flowers = 0;
            }

            // One bouquet formed
            if(flowers == k) {
                bouquets++;
                flowers = 0;
            }
        }

        return bouquets >= m;
    }
};
