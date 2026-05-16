# 🌊 Tree BFS Patterns

> “DFS explores depth.
> BFS explores structure.” 🌳

This section contains Breadth First Search (BFS) patterns on binary trees using queues.

BFS is extremely important for:

* level-wise traversal 🌊
* visibility problems 👀
* shortest-level processing ⚡
* indexed tree traversal 🔢

---

# 📂 Problems Included

```bash id="7p3tvm"
BFS/
├── level_order_traversal.cpp
├── zigzag_level_order_traversal.cpp
├── right_side_view.cpp
├── left_view_of_binary_tree.cpp
├── maximum_width_of_binary_tree.cpp
```

---

# 🔥 Core BFS Patterns Covered

| Pattern                   | Problem                      |
| ------------------------- | ---------------------------- |
| Standard Level Traversal  | Level Order Traversal        |
| Alternating Direction BFS | Zigzag Level Order           |
| Visibility Traversal      | Right Side View              |
| First Node Per Level      | Left View of Binary Tree     |
| Indexed BFS Traversal     | Maximum Width of Binary Tree |

---

# ⚙️ Standard BFS Template

```cpp id="yo78j0"
queue<TreeNode*> q;

q.push(root);

while(!q.empty()) {

    int levelSize = q.size();

    for(int i = 0; i < levelSize; i++) {

        TreeNode* node = q.front();
        q.pop();

        // process node

        if(node->left) {
            q.push(node->left);
        }

        if(node->right) {
            q.push(node->right);
        }
    }
}
```

---

# 💡 The Biggest Insight

BFS processes:

# 🌊 one complete level at a time.

That makes it perfect for:

* level-based computations
* visibility problems
* width calculations
* shortest-step traversal

---

# 🔥 Important BFS Techniques

## 👀 Level Observation

```cpp id="g0v6cp"
if(i == 0)
```

Used in:

* Left View
* Right Side View

---

## 🔄 Direction Control

```cpp id="p5c9ew"
leftToRight = !leftToRight
```

Used in:

* Zigzag Traversal

---

## 🔢 Indexed BFS

```cpp id="f6m3zt"
2 * index + 1
2 * index + 2
```

Used in:

* Maximum Width of Binary Tree

---

# ⚠️ Common Mistakes

* Forgetting level-size processing ❌
* Mixing DFS logic into BFS ❌
* Overflow in indexed traversal ❌
* Incorrect queue order ❌

---

# 🧠 What Tree BFS Really Teaches

Tree BFS improves:

* queue intuition 🌊
* level-wise thinking 🔄
* traversal customization ⚡
* structural tree understanding 🌳

---

# 🚀 Interview Insight

Most BFS tree problems are variations of:

```text id="p7x4lu"
“Process nodes level by level.”
```

The real challenge is:

```text id="r9n2vk"
“What extra information should be tracked?”
```

---

# 🏁 Final Thought

BFS on trees transforms traversal from:

```text id="4j8m1f"
depth exploration
```

to:

```text id="x2r6wp"
level-wise structural analysis
```

That shift is a major step in mastering trees. 🔥

---

⭐ If this helped, consider starring the repo!
