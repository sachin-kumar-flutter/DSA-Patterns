/*
-------------------------------------
🧩 Problem: Diameter of Binary Tree
📂 Category: Trees / DFS
🧠 Concept: Height + global answer update

⚡ Approach:
- Compute height recursively
- Diameter through current node:
    left height + right height
- Track maximum diameter globally

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(h)

🎯 Key Idea:
- Use DFS to compute height and diameter together

-------------------------------------
*/

class Solution {
public:

    int diameterValue = 0;

    int diameter(Node* root) {

        dfs(root);

        return diameterValue;
    }

    int dfs(Node* root) {

        // Empty subtree
        if(!root) {
            return 0;
        }

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

        // Update diameter
        diameterValue = max(
            diameterValue,
            leftHeight + rightHeight
        );

        // Return subtree height
        return 1 + max(leftHeight, rightHeight);
    }
};
