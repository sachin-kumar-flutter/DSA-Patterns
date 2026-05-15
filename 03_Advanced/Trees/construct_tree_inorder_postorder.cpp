/*
-------------------------------------
🧩 Problem: Construct Binary Tree from
    Inorder and Postorder Traversal

📂 Category: Advanced Trees / DFS
🧠 Concept: Recursive tree reconstruction

⚡ Approach:
- Postorder gives current root
- Inorder splits left/right subtree
- Traverse postorder backwards
- Build right subtree before left subtree

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Reverse postorder processing:
    root → right → left

-------------------------------------
*/

class Solution {
public:

    unordered_map<int, int> inorderIndex;

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int n = inorder.size();

        // Store inorder positions
        for(int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }

        int postIdx = n - 1;

        return build(postorder,
                     0,
                     n - 1,
                     postIdx);
    }

    TreeNode* build(vector<int>& postorder,
                    int start,
                    int end,
                    int& postIdx) {

        // Invalid subtree
        if(start > end) {
            return NULL;
        }

        // Current root from postorder
        TreeNode* root =
            new TreeNode(postorder[postIdx--]);

        int position = inorderIndex[root->val];

        // Build right subtree first
        root->right =
            build(postorder,
                  position + 1,
                  end,
                  postIdx);

        // Build left subtree
        root->left =
            build(postorder,
                  start,
                  position - 1,
                  postIdx);

        return root;
    }
};
