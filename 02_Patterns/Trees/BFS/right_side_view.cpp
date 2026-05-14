/*
-------------------------------------
🧩 Problem: Binary Tree Right Side View
📂 Category: Trees / BFS
🧠 Concept: Visible nodes from right side

⚡ Approach:
- Perform level-order traversal
- Push right child before left child
- First node at each level becomes visible

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Prioritize right subtree during BFS

-------------------------------------
*/

class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++) {

                TreeNode* node = q.front();
                q.pop();

                // First node seen from right
                if(i == 0) {
                    ans.push_back(node->val);
                }

                // Push right first
                if(node->right) {
                    q.push(node->right);
                }

                if(node->left) {
                    q.push(node->left);
                }
            }
        }

        return ans;
    }
};
