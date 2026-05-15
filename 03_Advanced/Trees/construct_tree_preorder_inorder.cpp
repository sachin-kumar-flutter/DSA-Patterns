/*
-------------------------------------
🧩 Problem: Construct Binary Tree from
    Preorder and Inorder Traversal

📂 Category: Advanced Trees / DFS
🧠 Concept: Recursive tree reconstruction

⚡ Approach:
- Preorder gives current root
- Inorder splits left/right subtree
- Use hashmap for O(1) inorder lookup
- Recursively build subtrees

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Preorder determines root order
- Inorder determines subtree boundaries

-------------------------------------
*/

class Solution {
public:

    unordered_map<int, int> inorderIndex;

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        int n = inorder.size();

        // Store inorder positions
        for(int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }

        int preorderIdx = 0;

        return build(preorder,
                     0,
                     n - 1,
                     preorderIdx);
    }

    TreeNode* build(vector<int>& preorder,
                    int left,
                    int right,
                    int& preorderIdx) {

        // Invalid subtree
        if(left > right) {
            return NULL;
        }

        // Current root from preorder
        TreeNode* root =
            new TreeNode(preorder[preorderIdx++]);

        int position = inorderIndex[root->val];

        // Build left subtree
        root->left =
            build(preorder,
                  left,
                  position - 1,
                  preorderIdx);

        // Build right subtree
        root->right =
            build(preorder,
                  position + 1,
                  right,
                  preorderIdx);

        return root;
    }
};
