/*
-------------------------------------
🧩 Problem: Maximum Depth of Binary Tree
📂 Category: Trees / DFS
🧠 Concept: Height recursion

⚡ Approach:
- Height of tree =
    1 + max(left height, right height)

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

-------------------------------------
*/

class Solution {
public:

    int maxDepth(TreeNode* root) {

        // Empty tree
        if(!root) {
            return 0;
        }

        return 1 + max(
            maxDepth(root->left),
            maxDepth(root->right)
        );
    }
};
