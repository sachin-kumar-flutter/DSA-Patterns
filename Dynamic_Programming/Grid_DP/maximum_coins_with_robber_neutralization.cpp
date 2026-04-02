// Problem: Maximum Coins with Robber Neutralization
// Approach: 3D Dynamic Programming
// Author: Sachin
// Notes: Classic grid DP with limited resource (k = 2 neutralizations)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();

        // dp[i][j][k] = maximum coins collected at cell (i,j)
        // using exactly k neutralizations (k = 0,1,2)
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        // Base case: starting cell (0,0)
        dp[0][0][0] = coins[0][0];

        // If starting cell has robber, we can neutralize it
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }

        // Traverse the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= 2; k++) {

                    // Skip invalid states
                    if (dp[i][j][k] == INT_MIN) continue;

                    // ------------------ MOVE RIGHT ------------------
                    if (j + 1 < n) {
                        int val = coins[i][j + 1];

                        // Case 1: Do NOT neutralize
                        dp[i][j + 1][k] = max(dp[i][j + 1][k],
                                               dp[i][j][k] + val);

                        // Case 2: Neutralize robber (only if negative and we have capacity)
                        if (val < 0 && k < 2) {
                            dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1],
                                                      dp[i][j][k]);
                        }
                    }

                    // ------------------ MOVE DOWN ------------------
                    if (i + 1 < m) {
                        int val = coins[i + 1][j];

                        // Case 1: Do NOT neutralize
                        dp[i + 1][j][k] = max(dp[i + 1][j][k],
                                               dp[i][j][k] + val);

                        // Case 2: Neutralize robber
                        if (val < 0 && k < 2) {
                            dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1],
                                                      dp[i][j][k]);
                        }
                    }
                }
            }
        }

        // Final answer: maximum among all possible neutralization usages
        return max({dp[m - 1][n - 1][0],
                    dp[m - 1][n - 1][1],
                    dp[m - 1][n - 1][2]});
    }
};
