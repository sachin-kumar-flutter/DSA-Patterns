/*
-------------------------------------
🧩 Problem: Delete Node in a BST
📂 Category: Trees / BST
🧠 Concept: BST deletion cases

⚡ Approach:
- Search for target node
- Handle 3 cases:
    1. Leaf node
    2. One child
    3. Two children
- Replace with inorder predecessor

⏱️ Time Complexity: O(h)
💾 Space Complexity: O(h)

🎯 Key Idea:
- Preserve BST ordering after deletion

-------------------------------------
*/

class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root) {
            return NULL;
        }

        // Search right subtree
        if(root->val < key) {

            root->right =
                deleteNode(root->right, key);
        }

        // Search left subtree
        else if(root->val > key) {

            root->left =
                deleteNode(root->left, key);
        }

        // Node found
        else {

            // Case 1: Leaf node
            if(!root->left && !root->right) {

                delete root;

                return NULL;
            }

            // Case 2: Only right child
            else if(!root->left) {

                TreeNode* temp = root->right;

                delete root;

                return temp;
            }

            // Case 3: Only left child
            else if(!root->right) {

                TreeNode* temp = root->left;

                delete root;

                return temp;
            }

            // Case 4: Two children
            TreeNode* predecessor =
                findMax(root->left);

            root->val = predecessor->val;

            root->left =
                deleteNode(root->left,
                           predecessor->val);
        }

        return root;
    }

    // Find inorder predecessor
    TreeNode* findMax(TreeNode* root) {

        while(root->right) {

            root = root->right;
        }

        return root;
    }
};
