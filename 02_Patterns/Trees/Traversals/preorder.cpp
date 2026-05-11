/*
-------------------------------------
🧩 Problem: Binary Tree Preorder Traversal
📂 Category: Trees / Traversals
🧠 Concept: Root → Left → Right

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

-------------------------------------
*/

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        preorder(root, ans);

        return ans;
    }

    void preorder(TreeNode* root,
                  vector<int>& ans) {

        if(!root) {
            return;
        }

        ans.push_back(root->val);

        preorder(root->left, ans);

        preorder(root->right, ans);
    }
};
