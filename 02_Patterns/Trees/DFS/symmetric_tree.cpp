/*
-------------------------------------
🧩 Problem: Symmetric Tree
📂 Category: Trees / DFS
🧠 Concept: Mirror recursion

⚡ Approach:
- Compare left subtree with right subtree
- Mirror conditions:
    → values must match
    → left.left ↔ right.right
    → left.right ↔ right.left

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

🎯 Key Idea:
- Recursively compare mirrored nodes

-------------------------------------
*/

class Solution {
public:

    bool isSymmetric(TreeNode* root) {

        if(!root) {
            return true;
        }

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* leftNode,
                  TreeNode* rightNode) {

        // One node missing
        if(leftNode == NULL || rightNode == NULL) {
            return leftNode == rightNode;
        }

        return leftNode->val == rightNode->val &&

               isMirror(leftNode->left,
                        rightNode->right) &&

               isMirror(leftNode->right,
                        rightNode->left);
    }
};
