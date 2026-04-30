# Linked List

## 📌 What is a Linked List?

A linked list is a linear data structure where elements (nodes) are stored **non-contiguously**, and each node contains:

* Data
* Pointer to the next node

---

## 🧠 Types of Linked Lists

* Singly Linked List
* Doubly Linked List
* Circular Linked List

---

## ⚡ Key Properties

* Dynamic size (can grow/shrink)
* No contiguous memory required
* Efficient insertion and deletion

---

## ⏱️ Time Complexities

| Operation | Complexity |
| --------- | ---------- |
| Access    | O(n)       |
| Search    | O(n)       |
| Insertion | O(1)*      |
| Deletion  | O(1)*      |

* If position is known

---

## 🔗 Structure of a Node (C++)

```cpp
struct Node {
    int data;
    Node* next;
};
```

---

## 📍 Advantages

* Efficient insertion/deletion
* Dynamic memory allocation
* No shifting required

---

## ⚠️ Disadvantages

* No random access (no indexing)
* Extra memory for pointers
* More complex than arrays

---

## 🎯 When to Use Linked List

* Frequent insertions/deletions
* Unknown or changing size
* Implementing stacks, queues, etc.

---

## 🔥 Important Concepts

* Reverse a linked list
* Detect cycle (Floyd’s algorithm)
* Find middle node
* Merge two sorted lists
* Remove nth node from end

---

## 🧾 Notes

Linked Lists are frequently asked in interviews. Mastering pointer manipulation is key to solving most problems efficiently.
