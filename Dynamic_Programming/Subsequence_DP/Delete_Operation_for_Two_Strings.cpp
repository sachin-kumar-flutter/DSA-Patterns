// Problem: Delete Operation for Two Strings
// Pattern: Subsequence DP (LCS-based Transformation)
// Difficulty: Medium

// Key Idea:
// We want to make both strings equal using minimum deletions.
// The optimal strategy is to keep the Longest Common Subsequence (LCS)
// and delete all other characters from both strings.

// Formula:
// Minimum deletions = len(word1) + len(word2) - 2 * LCS

// DP State:
// dp[i][j] = length of LCS between
//            word1[0..i-1] and word2[0..j-1]

// Transition:
// If characters match:
//     dp[i][j] = 1 + dp[i-1][j-1]
// Else:
//     dp[i][j] = max(dp[i-1][j], dp[i][j-1])

// Base Case:
// dp[0][j] = 0, dp[i][0] = 0

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

// Tags: DP, LCS, String, Subsequence

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Compute LCS length
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Minimum deletions required
        return m + n - 2 * dp[m][n];
    }
};
