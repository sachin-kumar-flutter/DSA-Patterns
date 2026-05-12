/*
-------------------------------------
🧩 Problem: Same Tree
📂 Category: Trees / DFS
🧠 Concept: Structural recursion

⚡ Approach:
- Both nodes must:
    → exist
    → have same value
    → left subtrees match
    → right subtrees match

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

-------------------------------------
*/

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If either is NULL
        if(p == NULL || q == NULL) {
            return p == q;
        }

        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
