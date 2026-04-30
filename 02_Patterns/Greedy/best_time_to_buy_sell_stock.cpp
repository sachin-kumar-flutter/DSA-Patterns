#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Best Time to Buy and Sell Stock

    Approach:
    ----------
    1. We need to maximize profit = selling price - buying price
    2. We must buy before we sell

    3. Track the minimum price seen so far (minSoFar)
    4. For each day:
        - Treat current price as selling price
        - Profit = prices[i] - minSoFar
        - Update maximum profit

    5. Also update minSoFar continuously

    Key Insight:
    ----------
    Instead of checking all pairs (O(n^2)),
    we keep track of the best buying price so far.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        // Minimum price seen so far (best day to buy)
        int minSoFar = prices[0];

        for (int i = 1; i < prices.size(); i++) {

            // Update minimum price
            minSoFar = min(minSoFar, prices[i]);

            // Calculate profit if selling today
            int currentProfit = prices[i] - minSoFar;

            // Update maximum profit
            profit = max(profit, currentProfit);
        }

        return profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution obj;
    cout << "Max Profit: " << obj.maxProfit(prices) << endl;
    return 0;
}
