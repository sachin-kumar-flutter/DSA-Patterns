/*
-------------------------------------
🧩 Problem: Invert Binary Tree
📂 Category: Trees / DFS
🧠 Concept: Modify tree recursively

⚡ Approach:
- Swap left and right child
- Recursively invert subtrees

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

-------------------------------------
*/

class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {

        if(!root) {
            return NULL;
        }

        // Swap children
        swap(root->left, root->right);

        // Invert subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
