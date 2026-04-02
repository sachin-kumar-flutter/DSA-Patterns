// Problem: Sum of Matrix After Queries
// Pattern: Greedy + Reverse Processing
// Difficulty: Medium

// Key Idea:
// In a sequence of updates, only the LAST update to each row or column matters.
// So instead of processing forward, we process queries in reverse.

// Intuition:
// - Once a row/column is updated for the first time (from the end),
//   it becomes "finalized"
// - Any earlier updates to that same row/column are irrelevant
// - This avoids unnecessary repeated work

// Approach:
// - Traverse queries from last to first
// - Maintain visited arrays: rowDone[] and colDone[]
// - Keep track of remaining rows and columns (rowLeft, colLeft)
// - For a row update → contributes val * remaining columns
// - For a column update → contributes val * remaining rows

// Why Greedy?
// We greedily take the last valid update for each row/column,
// ensuring maximum contribution without redundancy.

// Time Complexity: O(q + n)
// Space Complexity: O(n)

// Tags: Greedy, Reverse Processing, Matrix, Optimization

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rowDone(n, false), colDone(n, false);

        int rowLeft = n, colLeft = n;
        long long sum = 0;

        // Process queries in reverse
        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];

            if (type == 0) { // row update
                if (!rowDone[index]) {
                    sum += 1LL * val * colLeft;
                    rowDone[index] = true;
                    rowLeft--;
                }
            } else { // column update
                if (!colDone[index]) {
                    sum += 1LL * val * rowLeft;
                    colDone[index] = true;
                    colLeft--;
                }
            }
        }
        return sum;
    }
};
