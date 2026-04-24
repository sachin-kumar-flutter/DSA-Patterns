/*
    Pattern: Greedy (Kadane Variation / Subarray Optimization)
    Problem: Maximum Product Subarray

    Approach:
    ----------
    Unlike sum, product behaves differently due to negative numbers.

    Key Observations:
    - A negative number can turn a small (negative) product into a large positive one
    - So we must track BOTH:
        → maxProduct (maximum product ending at current index)
        → minProduct (minimum product ending at current index)

    Why minProduct?
    Because multiplying two negatives can give a large positive.

    Algorithm:
    ----------
    1. Initialize:
        maxProduct = arr[0]
        minProduct = arr[0]
        ans = arr[0]

    2. Traverse array:
        - If current element is negative → swap(maxProduct, minProduct)
        - Update:
            maxProduct = max(x, maxProduct * x)
            minProduct = min(x, minProduct * x)
        - Update answer:
            ans = max(ans, maxProduct)

    Key Insight:
    ------------
    We maintain both extremes because:
    → max can become min
    → min can become max (after multiplying by negative)

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int maxProduct = arr[0];   // max product ending here
        int minProduct = arr[0];   // min product ending here
        int ans = arr[0];          // global maximum product

        for(int i = 1; i < arr.size(); i++) {
            int x = arr[i];

            // If negative, swap roles of max and min
            if(x < 0) 
                swap(maxProduct, minProduct);

            // Update max and min products
            maxProduct = max(x, maxProduct * x);
            minProduct = min(x, minProduct * x);

            // Update answer
            ans = max(ans, maxProduct);
        }

        return ans;
    }
};
