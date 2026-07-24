class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Sort candies by price so we can greedily control which ones
        // count as "bought" vs "free" from either end
        sort(prices.begin(), prices.end());

        // ---------- Minimize total cost ----------
        // Strategy: buy the CHEAPEST candy, and get the k MOST EXPENSIVE
        // remaining candies for free. This way, the costly candies are
        // always the "free" ones, minimizing what we actually pay.
        int i = 0, j = prices.size() - 1;
        int minimum = 0;

        while (i <= j) {
            minimum += prices[i];   // pay for the cheapest available candy
            i++;                    // move past the one we just bought
            j -= k;                 // skip k candies from the expensive end (they're free)
        }

        // ---------- Maximize total cost ----------
        // Strategy: buy the MOST EXPENSIVE candy, and get the k CHEAPEST
        // remaining candies for free. This way, the cheap candies are
        // always the "free" ones, maximizing what we end up paying.
        int maximum = 0;
        j = 0;
        i = prices.size() - 1;

        while (j <= i) {
            maximum += prices[i];   // pay for the most expensive available candy
            i--;                    // move past the one we just bought
            j += k;                 // skip k candies from the cheap end (they're free)
        }

        return {minimum, maximum};
    }
};
