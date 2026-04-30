# 📚 Heap

## 📌 What is a Heap?

A heap is a **complete binary tree** that satisfies the **heap property**.

👉 Think of it as a tree where the “most important” element is always at the top.

---

## ⚡ Types of Heap

* **Max Heap** 🔼
  Parent ≥ Children
  → Maximum element at root

* **Min Heap** 🔽
  Parent ≤ Children
  → Minimum element at root

---

## 🌳 Key Properties

* Complete Binary Tree (filled level by level)
* Efficient insertion and deletion
* Typically implemented using arrays

---

## 📍 Array Representation

For a node at index `i`:

* Left Child → `2*i + 1`
* Right Child → `2*i + 2`
* Parent → `(i - 1) / 2`

---

## ⏱️ Time Complexities

| Operation     | Complexity |
| ------------- | ---------- |
| Insert        | O(log n)   |
| Delete (root) | O(log n)   |
| Heapify       | O(log n)   |
| Build Heap    | O(n)       |
| Peek (top)    | O(1)       |

---

## 🛠️ Core Operations

* **Insert (push)**
* **Delete (pop)**
* **Heapify (fix heap property)**
* **Build Heap**

---

## 🎯 When to Use Heap?

* Finding **kth largest/smallest** element
* Priority-based problems
* Top K elements
* Heap sort
* Dijkstra’s algorithm

---

## 🔥 Important Problems

* Kth Largest Element
* Top K Frequent Elements
* Merge K Sorted Arrays
* Median in a Stream
* Heap Sort

---

## ⚠️ Common Pitfalls

* Confusing heap with BST ❌
* Forgetting complete tree property
* Incorrect index calculations

---

## 💡 Key Insight

Heaps are all about **priority and efficiency**.

Whenever you see:

* “Top K”
* “Minimum/Maximum quickly”
  👉 Think **Heap immediately**

---

## 🧾 Notes

Heap is one of the most practical data structures used in real-world systems and interviews.
Mastering heap operations and patterns gives a strong edge in problem-solving.
