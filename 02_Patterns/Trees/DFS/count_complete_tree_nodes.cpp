/*
-------------------------------------
🧩 Problem: Count Complete Tree Nodes
📂 Category: Trees / DFS
🧠 Concept: Recursive aggregation

⚡ Approach:
- Count current node
- Add left subtree count
- Add right subtree count

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

-------------------------------------
*/

class Solution {
public:

    int countNodes(TreeNode* root) {

        // Empty tree
        if(!root) {
            return 0;
        }

        return 1 +
               countNodes(root->left) +
               countNodes(root->right);
    }
};
