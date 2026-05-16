# 🌲 Tree DFS Patterns

> “DFS on trees is where recursion truly starts making sense.” 🔥

This section contains core Depth First Search (DFS) patterns on binary trees.

These problems build strong intuition for:

* recursive traversal 🌳
* subtree computation ⚡
* structural recursion 🧠
* bottom-up information flow 🔄

---

# 📂 Problems Included

```bash
DFS/
├── maximum_depth.cpp
├── same_tree.cpp
├── invert_binary_tree.cpp
├── count_complete_tree_nodes.cpp
├── diameter_of_binary_tree.cpp
├── balanced_binary_tree.cpp
├── lowest_common_ancestor.cpp
├── symmetric_tree.cpp
```

---

# 🔥 Core DFS Patterns Covered

| Pattern                | Problem                   |
| ---------------------- | ------------------------- |
| Height Recursion       | Maximum Depth             |
| Structural Comparison  | Same Tree                 |
| Tree Modification      | Invert Binary Tree        |
| Recursive Aggregation  | Count Complete Tree Nodes |
| Height + Global Answer | Diameter of Binary Tree   |
| DFS Pruning            | Balanced Binary Tree      |
| Recursive Propagation  | Lowest Common Ancestor    |
| Mirror Recursion       | Symmetric Tree            |

---

# ⚙️ Standard DFS Template

```cpp
int dfs(TreeNode* root) {

    if(!root) {
        return base_value;
    }

    int left = dfs(root->left);
    int right = dfs(root->right);

    // process current node

    return result;
}
```

---

# 💡 The Biggest Insight

Tree DFS is NOT just traversal.

Every recursive call answers:

```text
“What information should I return upward?”
```

That single idea unlocks:

* diameter problems
* balance checking
* tree DP
* ancestor problems

---

# 🌳 Important DFS Styles

## 1️⃣ Top-Down DFS

Pass information downward.

Example:

* Path Sum

---

## 2️⃣ Bottom-Up DFS

Collect information upward.

Examples:

* Diameter of Binary Tree
* Balanced Binary Tree
* Lowest Common Ancestor

---

# 🔥 Key Techniques Used

## ⚡ DFS Pruning

```cpp
if(left == -1) return -1;
```

Used in:

* Balanced Binary Tree

---

## 🌲 Global Answer Update

```cpp
ans = max(ans, left + right);
```

Used in:

* Diameter of Binary Tree

---

## 🔄 Mirror Recursion

```cpp
left.left ↔ right.right
```

Used in:

* Symmetric Tree

---

# ⚠️ Common Mistakes

* Forgetting base cases ❌
* Returning wrong subtree information ❌
* Confusing height vs diameter ❌
* Recomputing heights repeatedly ❌

---

# 🧠 What Tree DFS Really Teaches

Tree DFS improves:

* recursive thinking 🌳
* divide-and-conquer intuition ⚡
* state propagation 🔄
* bottom-up reasoning 🧠

---

# 🚀 Interview Insight

Most strong tree solutions are based on:

```text
“Compute subtree information recursively.”
```

Once that mindset becomes natural,
tree problems become much easier.

---

# 🏁 Final Thought

DFS on trees is where recursion evolves from:

```text
simple traversal
```

to:

```text
intelligent subtree computation
```

That transition is one of the biggest milestones in DSA. 🔥

---

⭐ If this helped, consider starring the repo!
