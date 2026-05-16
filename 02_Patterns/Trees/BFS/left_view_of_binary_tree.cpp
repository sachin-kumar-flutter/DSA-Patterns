/*
-------------------------------------
🧩 Problem: Left View of Binary Tree
📂 Category: Trees / BFS
🧠 Concept: Visible nodes from left side

⚡ Approach:
- Perform level-order traversal
- First node at every level
  becomes part of left view

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Capture first node of each level

-------------------------------------
*/

class Solution {
public:

    vector<int> leftView(Node* root) {

        vector<int> ans;

        if(!root) {
            return ans;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {

            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++) {

                Node* current = q.front();
                q.pop();

                // First node of level
                if(i == 0) {
                    ans.push_back(current->data);
                }

                if(current->left) {
                    q.push(current->left);
                }

                if(current->right) {
                    q.push(current->right);
                }
            }
        }

        return ans;
    }
};
