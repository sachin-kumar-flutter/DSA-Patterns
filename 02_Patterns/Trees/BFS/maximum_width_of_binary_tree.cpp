/*
-------------------------------------
🧩 Problem: Maximum Width of Binary Tree
📂 Category: Trees / BFS
🧠 Concept: Indexed level-order traversal

⚡ Approach:
- Assign virtual indices to nodes
- Normalize indices at every level
- Width = lastIndex - firstIndex + 1

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Simulate complete binary tree indexing

-------------------------------------
*/

class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {

        if(!root) {
            return 0;
        }

        long long maxWidth = 0;

        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()) {

            int levelSize = q.size();

            long long first, last;

            // Prevent overflow
            long long minIndex = q.front().second;

            for(int i = 0; i < levelSize; i++) {

                auto [node, index] = q.front();
                q.pop();

                index -= minIndex;

                if(i == 0) {
                    first = index;
                }

                if(i == levelSize - 1) {
                    last = index;
                }

                if(node->left) {
                    q.push({node->left, 2 * index + 1});
                }

                if(node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }

            maxWidth = max(
                maxWidth,
                last - first + 1
            );
        }

        return maxWidth;
    }
};
