/*
-------------------------------------
🧩 Problem: Lowest Common Ancestor of a Binary Tree
📂 Category: Trees / DFS
🧠 Concept: Bottom-up recursive propagation

⚡ Approach:
- If current node matches p or q:
    return current node
- Search left and right subtree
- If both sides return non-null:
    current node is LCA
- Otherwise propagate non-null node upward

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

🎯 Key Idea:
- Information flows upward during recursion

-------------------------------------
*/

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        // Base cases
        if(!root || root == p || root == q) {
            return root;
        }

        TreeNode* left =
            lowestCommonAncestor(root->left, p, q);

        TreeNode* right =
            lowestCommonAncestor(root->right, p, q);

        // p and q found in different subtrees
        if(left && right) {
            return root;
        }

        // Propagate non-null result upward
        return left ? left : right;
    }
};
