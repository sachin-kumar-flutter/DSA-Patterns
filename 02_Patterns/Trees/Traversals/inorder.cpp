/*
-------------------------------------
🧩 Problem: Binary Tree Inorder Traversal
📂 Category: Trees / Traversals
🧠 Concept: Left → Root → Right

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

-------------------------------------
*/

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        inorder(root, ans);

        return ans;
    }

    void inorder(TreeNode* root,
                 vector<int>& ans) {

        if(!root) {
            return;
        }

        inorder(root->left, ans);

        ans.push_back(root->val);

        inorder(root->right, ans);
    }
};
