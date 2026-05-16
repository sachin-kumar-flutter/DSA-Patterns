/*
-------------------------------------
🧩 Problem: Lowest Common Ancestor of BST
📂 Category: Trees / BST
🧠 Concept: BST-guided traversal

⚡ Approach:
- If both nodes are smaller:
    move left
- If both nodes are greater:
    move right
- Otherwise current node is LCA

⏱️ Time Complexity: O(h)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Use BST ordering to avoid full DFS

-------------------------------------
*/

class Solution {
public:

    Node* LCA(Node* root,
              Node* n1,
              Node* n2) {

        while(root) {

            // Both nodes in left subtree
            if(root->data > n1->data &&
               root->data > n2->data) {

                root = root->left;
            }

            // Both nodes in right subtree
            else if(root->data < n1->data &&
                    root->data < n2->data) {

                root = root->right;
            }

            // Split point found
            else {
                break;
            }
        }

        return root;
    }
};
