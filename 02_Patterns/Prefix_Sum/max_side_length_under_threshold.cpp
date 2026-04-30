// Problem: Maximum Side Length of a Square with Sum ≤ Threshold
// Pattern: Prefix Sum + Binary Search
// Difficulty: Medium

// Key Idea:
// We need to find the largest square such that its sum is ≤ threshold.
// Instead of checking all sizes directly, we use binary search on side length.

// Intuition:
// - Larger squares have larger sums
// - If a square of size k is valid, smaller sizes are also valid
// → This monotonic property allows binary search

// Approach:
// - Build a 2D prefix sum array for fast submatrix sum queries
// - Binary search on side length (1 → min(m, n))
// - For each candidate size:
//     • Check all possible k x k squares
//     • Compute sum in O(1) using prefix sum
// - If any square satisfies condition → try larger size

// Why Prefix Sum?
// Allows constant-time calculation of any submatrix sum

// Why Binary Search?
// Exploits monotonic behavior of square size vs sum constraint

// Time Complexity: O(m * n * log(min(m, n)))
// Space Complexity: O(m * n)

// Tags: Prefix Sum, Binary Search, Matrix, Optimization

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // 2D prefix sum array
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        int low = 1, high = min(m, n), ans = 0;

        // Binary search on side length
        while (low <= high) {
            int mid = (low + high) / 2;
            bool possible = false;

            // Check all squares of side length = mid
            for (int i = 0; i + mid <= m && !possible; i++) {
                for (int j = 0; j + mid <= n; j++) {
                    int sum = prefix[i + mid][j + mid]
                            - prefix[i][j + mid]
                            - prefix[i + mid][j]
                            + prefix[i][j];

                    if (sum <= threshold) {
                        possible = true;
                        break;
                    }
                }
            }

            if (possible) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
