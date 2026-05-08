/*
-------------------------------------
🧩 Problem: Capacity To Ship Packages Within D Days
📂 Category: Binary Search (Binary Search on Answer)
🧠 Concept: Minimize feasible ship capacity

⚡ Approach:
- Search capacity in range:
    [max(weights), sum(weights)]
- Check if packages can be shipped
  within given days
- Minimize the feasible capacity

⏱️ Time Complexity: O(n log(sum))
💾 Space Complexity: O(1)

🎯 Key Idea:
- Binary search on feasible capacity

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        int ans = right;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(isPossible(weights, days, mid)) {
                ans = mid;
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(vector<int>& weights, int days, int capacity) {

        int currentWeight = 0;
        int requiredDays = 1;

        for(int x : weights) {

            if(currentWeight + x <= capacity) {
                currentWeight += x;
            }

            else {
                requiredDays++;
                currentWeight = x;
            }
        }

        return requiredDays <= days;
    }
};
