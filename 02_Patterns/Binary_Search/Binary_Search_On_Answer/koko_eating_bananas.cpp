/*
-------------------------------------
🧩 Problem: Koko Eating Bananas
📂 Category: Binary Search (Binary Search on Answer)
🧠 Concept: Minimize feasible eating speed

⚡ Approach:
- Search possible eating speed from:
    [1 ... max(piles)]
- Check if Koko can finish within h hours
- If possible:
    → try smaller speed
- Else:
    → increase speed

⏱️ Time Complexity: O(n log(maxPile))
💾 Space Complexity: O(1)

🎯 Key Idea:
- Binary search on feasible answers

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(canEat(piles, mid, h)) {
                ans = mid;
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    bool canEat(vector<int>& piles, int speed, int hours) {

        long long totalHours = 0;

        for(int bananas : piles) {
            totalHours += (bananas + speed - 1) / speed;
        }

        return totalHours <= hours;
    }
};
