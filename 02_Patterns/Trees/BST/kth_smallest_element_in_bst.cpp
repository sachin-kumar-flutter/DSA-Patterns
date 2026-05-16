/*
-------------------------------------
🧩 Problem: Kth Smallest Element in BST
📂 Category: Trees / BST
🧠 Concept: Inorder traversal property

⚡ Approach:
- Inorder traversal of BST
  gives sorted order
- Decrease k while traversing
- When k becomes 0:
    current node is answer

⏱️ Time Complexity: O(h + k)
💾 Space Complexity: O(h)

🎯 Key Idea:
- BST inorder traversal is sorted

-------------------------------------
*/

class Solution {
public:

    int answer = -1;

    int kthSmallest(Node* root, int k) {

        inorder(root, k);

        return answer;
    }

    void inorder(Node* root, int& k) {

        if(!root) {
            return;
        }

        // Visit left subtree
        inorder(root->left, k);

        // Process current node
        k--;

        if(k == 0) {
            answer = root->data;
            return;
        }

        // Visit right subtree
        inorder(root->right, k);
    }
};
