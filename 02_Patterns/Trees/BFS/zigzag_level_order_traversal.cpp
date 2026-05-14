/*
-------------------------------------
🧩 Problem: Binary Tree Zigzag Level Order Traversal
📂 Category: Trees / BFS
🧠 Concept: Alternating level traversal

⚡ Approach:
- Perform standard BFS
- Alternate insertion direction every level
- Use index mapping instead of reversing

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Control insertion index based on traversal direction

-------------------------------------
*/

class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()) {

            int levelSize = q.size();

            vector<int> level(levelSize);

            for(int i = 0; i < levelSize; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Determine insertion index
                int index = leftToRight
                            ? i
                            : levelSize - 1 - i;

                level[index] = node->val;

                if(node->left) {
                    q.push(node->left);
                }

                if(node->right) {
                    q.push(node->right);
                }
            }

            ans.push_back(level);

            // Toggle direction
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
