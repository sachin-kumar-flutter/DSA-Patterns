/*
-------------------------------------
🧩 Problem: BST Iterator
📂 Category: Trees / BST
🧠 Concept: Controlled inorder traversal

⚡ Approach:
- Maintain stack of left nodes
- next():
    return current smallest node
- After visiting node:
    process right subtree

⏱️ Time Complexity:
    next()    -> Average O(1)
    hasNext() -> O(1)

💾 Space Complexity: O(h)

🎯 Key Idea:
- Simulate inorder traversal lazily

-------------------------------------
*/

class BSTIterator {
public:

    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {

        pushLeft(root);
    }

    int next() {

        TreeNode* node = st.top();
        st.pop();

        // Process right subtree
        pushLeft(node->right);

        return node->val;
    }

    bool hasNext() {

        return !st.empty();
    }

    void pushLeft(TreeNode* node) {

        while(node) {

            st.push(node);

            node = node->left;
        }
    }
};
