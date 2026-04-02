// Problem: Largest Magic Square
// Pattern: Prefix Sum + Brute Force Optimization
// Difficulty: Medium

// Key Idea:
// We need to find the largest k x k square where:
// - All row sums are equal
// - All column sums are equal
// - Both diagonals have the same sum

// Intuition:
// - Directly checking sums repeatedly is expensive
// - Use prefix sums to compute row and column sums in O(1)
// - Try larger squares first (greedy-like optimization)
// - Return immediately when a valid square is found

// Approach:
// - Build row-wise and column-wise prefix sum arrays
// - Iterate over all possible square sizes (k from max → 2)
// - For each square:
//     • Check all row sums using prefix sums
//     • Check all column sums using prefix sums
//     • Compute both diagonals directly
// - If all match → return k

// Why Prefix Sum?
// Allows fast computation of submatrix row/column sums,
// reducing repeated work from O(k) to O(1)

// Time Complexity: O(min(m, n)^3)
// Space Complexity: O(m * n)

// Tags: Prefix Sum, Matrix, Simulation, Optimization

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        // Build prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        int maxK = min(m, n);

        // Try largest square first
        for (int k = maxK; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    // Check all rows
                    for (int r = i; r < i + k; r++) {
                        if (row[r][j + k] - row[r][j] != target) {
                            ok = false;
                            break;
                        }
                    }

                    // Check all columns
                    for (int c = j; c < j + k && ok; c++) {
                        if (col[i + k][c] - col[i][c] != target) {
                            ok = false;
                            break;
                        }
                    }

                    // Check diagonals
                    int d1 = 0, d2 = 0;
                    for (int t = 0; t < k; t++) {
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t];
                    }

                    if (ok && d1 == target && d2 == target)
                        return k;
                }
            }
        }
        return 1;
    }
};
