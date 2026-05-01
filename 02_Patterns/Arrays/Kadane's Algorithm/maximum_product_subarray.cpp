/*
-------------------------------------
🧩 Problem: Maximum Product Subarray
📂 Category: Arrays (Pattern - Kadane Variant)
🧠 Concept: Track both max and min product

⚡ Approach:
- Maintain:
    → maxProduct: maximum product ending at current index
    → minProduct: minimum product (important for negatives)
- If current number is negative → swap max and min
- Update both values at each step

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Negative × negative = positive
- So min product can become max later

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int maxProduct = arr[0];
        int minProduct = arr[0];
        int ans = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            int x = arr[i];

            // If negative, swap roles
            if(x < 0) swap(maxProduct, minProduct);

            // Update max and min products
            maxProduct = max(x, maxProduct * x);
            minProduct = min(x, minProduct * x);

            ans = max(ans, maxProduct);
        }

        return ans;
    }
};
