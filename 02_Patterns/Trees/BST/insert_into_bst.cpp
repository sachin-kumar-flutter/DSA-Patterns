/*
-------------------------------------
🧩 Problem: Insert into a Binary Search Tree
📂 Category: Trees / BST
🧠 Concept: BST-directed recursion

⚡ Approach:
- Compare value with current node
- Move left or right accordingly
- Insert node when NULL position found

⏱️ Time Complexity: O(h)
💾 Space Complexity: O(h)

🎯 Key Idea:
- BST property guides traversal direction

-------------------------------------
*/

class Solution {
public:

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // Insert new node
        if(!root) {
            return new TreeNode(val);
        }

        // Move left
        if(val < root->val) {

            root->left =
                insertIntoBST(root->left, val);
        }

        // Move right
        else {

            root->right =
                insertIntoBST(root->right, val);
        }

        return root;
    }
};
