/*
-------------------------------------
🧩 Problem: Binary Tree Maximum Path Sum
📂 Category: Advanced Trees / DFS
🧠 Concept: Tree DP + path contribution

⚡ Approach:
- Compute maximum contribution from left/right subtree
- Ignore negative paths using max(0, ...)
- Update global answer using:
    root + left + right
- Return best single-side contribution upward

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

🎯 Key Idea:
- Every node acts as a potential path center

-------------------------------------
*/

class Solution {
public:

    int maxPath = INT_MIN;

    int findMaxSum(Node* root) {

        dfs(root);

        return maxPath;
    }

    int dfs(Node* root) {

        // Empty subtree
        if(!root) {
            return 0;
        }

        // Ignore negative contributions
        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        // Path passing through current node
        maxPath = max(
            maxPath,
            root->data + leftGain + rightGain
        );

        // Return best contribution upward
        return root->data + max(leftGain, rightGain);
    }
};
