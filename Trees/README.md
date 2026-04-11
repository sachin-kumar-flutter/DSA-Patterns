# 🌳 Trees - Problem Solving Patterns

A structured collection of **Binary Tree patterns** focused on mastering recursion, traversal techniques, and hierarchical problem-solving — essential for coding interviews.

---

## 🧠 Core Concepts Covered

### 🔹 Tree Traversals

* **BFS (Level Order Traversal)**

  * Queue-based processing
  * Level-wise computation

* **DFS Traversals**

  * Preorder → Root → Left → Right
  * Inorder → Left → Root → Right
  * Postorder → Left → Right → Root

---

### 🔹 Recursion & Divide and Conquer

* Break problems into **left and right subtrees**
* Solve using:

  * **Top-down approach** (passing state)
  * **Bottom-up approach** (returning values)

---

### 🔹 Tree Construction

* Build trees using traversal combinations:

  * Inorder + Preorder
  * Inorder + Postorder
* Understand how structure is encoded in traversals

---

### 🔹 Height, Depth & Structural Properties

* Tree height and depth
* Balanced vs unbalanced trees
* Diameter of a tree
* Subtree properties and validations

---

## 📂 Directory Structure

```bash
Trees/
│
├── BFS/
│   └── Level order traversal and variations
│
├── DFS/
│   └── Recursive traversal and subtree-based problems
│
├── Construction/
│   └── Build tree from traversal arrays
```

---

## 🎯 Why Trees?

* 📌 One of the **most frequently asked topics** in interviews
* 📌 Strongly tests **recursion, problem decomposition, and edge cases**
* 📌 Foundation for advanced topics:

  * Graphs
  * Heaps
  * Segment Trees

---

## 🔥 Key Patterns to Master

* Traversal-based problems (DFS/BFS)
* Recursive subtree problems
* Tree construction from traversals
* Path-based problems (root-to-node, node-to-node)
* Height / diameter / balance computations

---

## ⚡ Key Takeaways

✔️ Most tree problems reduce to **DFS or BFS**
✔️ Think recursively — trees are naturally recursive
✔️ Decide early: **Top-down vs Bottom-up**
✔️ Handle edge cases (null nodes) carefully

---

## 🧠 Mental Model

When solving a tree problem, ask:

> 🔍 Can I break this into left and right subtree?
> 🔍 What should my function return?
> 🔍 Do I need to pass information down or return it up?
> 🔍 Is this a DFS or BFS problem?

---

## 🚀 Pro Tip

> “Every tree problem is a recursion problem in disguise.”

Master recursion here → Graphs and DP become much easier.

---
