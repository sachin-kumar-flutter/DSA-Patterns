/*
-------------------------------------
🧩 Problem: Best Time to Buy & Sell Stock (1 Transaction)
📂 Category: Arrays (Greedy Pattern)
🧠 Concept: Track Minimum Price

⚡ Approach:
- Keep track of minimum price seen so far
- At each step, calculate profit if sold today
- Update maximum profit

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Buy at lowest, sell at highest after it

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]); // best buying point
            maxProfit = max(maxProfit, prices[i] - minPrice); // best selling
        }

        return maxProfit;
    }
};
