/*
-------------------------------------
🧩 Problem: Best Time to Buy & Sell Stock (Multiple Transactions)
📂 Category: Arrays (Greedy Pattern)
🧠 Concept: Accumulate all increasing differences

⚡ Approach:
- Whenever price increases from previous day → take profit
- Add all such profits

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Capture every upward slope

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
