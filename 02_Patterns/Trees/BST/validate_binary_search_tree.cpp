/*
-------------------------------------
🧩 Problem: Validate Binary Search Tree
📂 Category: Trees / BST
🧠 Concept: Range-based DFS validation

⚡ Approach:
- Every node must lie within:
    (minValue, maxValue)
- Left subtree:
    values < current node
- Right subtree:
    values > current node
- Update valid range recursively

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

🎯 Key Idea:
- BST validity depends on ancestor constraints

-------------------------------------
*/

class Solution {
public:

    bool isValidBST(TreeNode* root) {

        return validate(
            root,
            LLONG_MIN,
            LLONG_MAX
        );
    }

    bool validate(TreeNode* root,
                  long long minValue,
                  long long maxValue) {

        // Empty subtree
        if(!root) {
            return true;
        }

        // Current node violates BST rule
        if(root->val <= minValue ||
           root->val >= maxValue) {

            return false;
        }

        return validate(
                    root->left,
                    minValue,
                    root->val
               ) &&

               validate(
                    root->right,
                    root->val,
                    maxValue
               );
    }
};
