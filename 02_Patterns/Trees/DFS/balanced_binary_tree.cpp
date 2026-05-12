/*
-------------------------------------
🧩 Problem: Balanced Binary Tree
📂 Category: Trees / DFS
🧠 Concept: Height-balanced recursion

⚡ Approach:
- Compute subtree heights recursively
- If any subtree becomes unbalanced:
    → return -1 immediately
- Use sentinel value for pruning

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

🎯 Key Idea:
- Combine balance check + height computation

-------------------------------------
*/

class Solution {
public:

    bool isBalanced(TreeNode* root) {

        return height(root) != -1;
    }

    int height(TreeNode* root) {

        // Empty subtree
        if(!root) {
            return 0;
        }

        int leftHeight = height(root->left);

        // Left subtree already unbalanced
        if(leftHeight == -1) {
            return -1;
        }

        int rightHeight = height(root->right);

        // Right subtree already unbalanced
        if(rightHeight == -1) {
            return -1;
        }

        // Current node unbalanced
        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + max(leftHeight, rightHeight);
    }
};
