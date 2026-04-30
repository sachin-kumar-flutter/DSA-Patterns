#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Best Time to Buy and Sell Stock II

    You can buy and sell multiple times (but must sell before buying again)

    ------------------------------------------------------------
    Approach 1: Greedy (Sum of all increasing differences)
    ------------------------------------------------------------
    Idea:
    - If price increases from previous day, take the profit
    - Add all such positive differences

    Why it works:
    - Any increasing sequence can be broken into smaller profits
    - Sum of small profits = one large transaction

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

int maxProfitGreedy(vector<int>& prices) {
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {
        // If price increases, take the profit
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

/*
    ------------------------------------------------------------
    Approach 2: Valley-Peak (Explicit buy-sell points)
    ------------------------------------------------------------
    Idea:
    - Find local minima (buy)
    - Find local maxima (sell)
    - Add profit

    This is more intuitive but slightly verbose
*/

int maxProfitValleyPeak(vector<int>& prices) {
    int n = prices.size();
    int i = 0, profit = 0;

    while (i < n - 1) {

        // Find valley (buy point)
        while (i < n - 1 && prices[i] >= prices[i + 1]) i++;
        int buy = prices[i];

        // Find peak (sell point)
        while (i < n - 1 && prices[i] <= prices[i + 1]) i++;
        int sell = prices[i];

        profit += sell - buy;
    }

    return profit;
}

/*
    Key Insight:
    ------------------------------------------------------------
    Greedy approach is preferred because:
    - Simpler and cleaner
    - Same result as valley-peak
    - Easier to implement in interviews
*/

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Greedy Profit: " << maxProfitGreedy(prices) << endl;
    cout << "Valley-Peak Profit: " << maxProfitValleyPeak(prices) << endl;

    return 0;
}
