# ⚡ Time Complexity Cheat Sheet

A quick reference guide to analyze and compare algorithm efficiency.

---

## 🚀 Big-O Notation (Growth Rate)

| Complexity | Name         | Example Use Case            |
| ---------- | ------------ | --------------------------- |
| O(1)       | Constant     | Array access                |
| O(log n)   | Logarithmic  | Binary Search               |
| O(n)       | Linear       | Traversing array            |
| O(n log n) | Linearithmic | Merge Sort, Quick Sort      |
| O(n²)      | Quadratic    | Bubble / Selection Sort     |
| O(2ⁿ)      | Exponential  | Recursion (subset problems) |
| O(n!)      | Factorial    | Permutations                |

---

## 📊 Common Data Structure Operations

### 🟢 Arrays

* Access → O(1)
* Search → O(n)
* Insert/Delete → O(n)

---

### 🔗 Linked List

* Access → O(n)
* Insert/Delete → O(1) (if position known)

---

### 📚 Stack / Queue

* Push / Pop / Enqueue / Dequeue → O(1)

---

### 🌳 Trees (Binary Tree / BST)

* Traversal → O(n)
* Search (BST) → O(log n)*

* Only if balanced

---

### 🔼 Heap

* Insert → O(log n)
* Delete → O(log n)
* Peek → O(1)

---

### 🗺️ Hash Table

* Insert / Search / Delete → O(1) average
* Worst case → O(n)

---

## 🔥 Sorting Complexities

| Algorithm      | Time Complexity |
| -------------- | --------------- |
| Bubble Sort    | O(n²)           |
| Selection Sort | O(n²)           |
| Insertion Sort | O(n²)           |
| Merge Sort     | O(n log n)      |
| Quick Sort     | O(n log n)*     |

* Worst case: O(n²)

---

## 🧠 Pattern-Based Complexities

* Sliding Window → O(n)
* Two Pointers → O(n)
* Prefix Sum → O(n) preprocessing
* Binary Search → O(log n)

---

## ⚠️ Important Notes

* Always consider **worst-case complexity** in interviews
* Space complexity matters too
* Constants don’t matter, growth rate does

---

## 💡 Key Insight

👉 The goal is not just to solve problems,
but to solve them **efficiently**.

---

## 🧾 Final Tip

If your solution is:

* O(n²) → Try optimizing
* O(n log n) → Usually acceptable
* O(n) → Ideal

---

Mastering time complexity helps you:

* Write better code
* Optimize solutions
* Crack interviews confidently 🚀
