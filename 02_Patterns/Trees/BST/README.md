# 🌳 Binary Search Tree (BST) Patterns

> “A Binary Search Tree is not just a tree.
> It is a tree that makes decisions.” ⚡

This section contains core Binary Search Tree (BST) patterns used in coding interviews.

BST problems are powerful because they combine:

* recursion 🌳
* ordering properties 🔢
* directed traversal ⚡
* efficient searching 🎯

Unlike normal binary trees, BSTs allow us to:

```text id="r8m2wx"
eliminate half the search space
```

---

# 📂 Problems Included

```bash id="q9p4nk"
BST/
├── validate_binary_search_tree.cpp
├── lowest_common_ancestor_bst.cpp
├── kth_smallest_element_in_bst.cpp
├── insert_into_bst.cpp
├── delete_node_in_bst.cpp
```

---

# 🔥 Core BST Patterns Covered

| Pattern                     | Problem                       |
| --------------------------- | ----------------------------- |
| Range Validation            | Validate Binary Search Tree   |
| Directed Traversal          | Lowest Common Ancestor in BST |
| Sorted Inorder Property     | Kth Smallest Element          |
| Recursive Insertion         | Insert into BST               |
| Tree Structure Preservation | Delete Node in BST            |

---

# ⚙️ Fundamental BST Property

For every node:

```text id="v2k8mq"
left subtree  <  root  <  right subtree
```

This single rule powers:

* searching
* insertion
* deletion
* inorder sorting
* pruning decisions

---

# 🌳 Important BST Concepts

## 🔍 Directed Traversal

Unlike normal trees:

```text id="m4t7xp"
BST traversal follows decisions
```

Example:

```cpp id="x3n9wr"
if(val < root->val)
```

Move left.

---

## 📈 Inorder Traversal

BST inorder traversal gives:

# 🔥 sorted order automatically

Used in:

* Kth Smallest Element
* BST Iterator
* Validation

---

## ⚡ Range Constraints

```cpp id="k5r1vp"
(minValue, maxValue)
```

Used in:

* Validate BST

Very important BST recursion pattern.

---

## 🪓 Deletion Logic

BST deletion requires:

```text id="w7m4zk"
preserving tree ordering
```

This introduces:

* inorder predecessor
* inorder successor

---

# ⚠️ Common Mistakes

* Checking only local BST conditions ❌
* Forgetting ancestor constraints ❌
* Wrong inorder assumptions ❌
* Incorrect deletion handling ❌

---

# 🧠 What BST Problems Really Teach

BSTs improve:

* decision-based traversal 🎯
* recursive constraints 🌳
* ordered data structure intuition 🔢
* logarithmic search thinking ⚡

---

# 🚀 Interview Insight

Most BST problems become easy once you recognize:

```text id="n8v3qp"
BST ordering eliminates unnecessary traversal
```

That’s the real superpower of BSTs.

---

# 🏁 Final Thought

A normal binary tree says:

```text id="5k1rqn"
“Explore everything.”
```

A BST says:

```text id="p2m7vx"
“I already know where to go.”
```

That difference is what makes BSTs beautiful. 🌳⚡

---

⭐ If this helped, consider starring the repo!
