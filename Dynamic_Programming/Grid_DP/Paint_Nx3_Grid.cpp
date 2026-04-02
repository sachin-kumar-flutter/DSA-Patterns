// Problem: Number of Ways to Paint N x 3 Grid
// Pattern: State Compression DP
// Difficulty: Medium

// Key Idea:
// Each row can be painted in two valid patterns:
// 1. same: all 3 colors are different (ABC type)
// 2. diff: two adjacent colors are same (ABA type)

// Transition:
// From previous row, we compute new counts based on valid combinations

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;

        // same: ways where all 3 colors are different
        // diff: ways where 2 adjacent colors are same
        long long same = 6, diff = 6;

        for(int i = 1; i < n; i++) {

            // Transition formulas
            long long newSame = (3 * same + 2 * diff) % mod;
            long long newDiff = (2 * same + 2 * diff) % mod;

            same = newSame;
            diff = newDiff;
        }

        return (same + diff) % mod;
    }
};
