/*
-------------------------------------
🧩 Problem: Binary Tree Level Order Traversal
📂 Category: Trees / BFS Traversal
🧠 Concept: Level-by-level traversal using queue

⚡ Approach:
- Use queue for BFS
- Process one level at a time
- Store nodes level-wise

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Queue maintains traversal order level by level

-------------------------------------
*/

class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int levelSize = q.size();

            vector<int> level;

            for(int i = 0; i < levelSize; i++) {

                TreeNode* current = q.front();
                q.pop();

                level.push_back(current->val);

                if(current->left) {
                    q.push(current->left);
                }

                if(current->right) {
                    q.push(current->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};
