/*
-------------------------------------
🧩 Problem: Binary Tree Postorder Traversal
📂 Category: Trees / Traversals
🧠 Concept: Left → Right → Root

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

-------------------------------------
*/

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        postorder(root, ans);

        return ans;
    }

    void postorder(TreeNode* root,
                   vector<int>& ans) {

        if(!root) {
            return;
        }

        postorder(root->left, ans);

        postorder(root->right, ans);

        ans.push_back(root->val);
    }
};
