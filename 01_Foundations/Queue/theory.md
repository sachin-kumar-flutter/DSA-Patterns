# 📚 Queue

## 📌 What is a Queue?

A queue is a linear data structure that follows the **FIFO (First In, First Out)** principle.

👉 Think of it like a line at a ticket counter — the first person in line gets served first.

---

## ⚡ Core Operations

* **enqueue(x)** → Insert element at the rear
* **dequeue()** → Remove element from the front
* **front()** → Access the front element
* **isEmpty()** → Check if queue is empty

---

## ⏱️ Time Complexities

| Operation | Complexity |
| --------- | ---------- |
| Enqueue   | O(1)       |
| Dequeue   | O(1)       |
| Front     | O(1)       |

---

## 🧠 Types of Queues

* **Simple Queue**
* **Circular Queue** 🔄
* **Deque (Double-ended Queue)** ↔️
* **Priority Queue** ⚡

---

## 🛠️ Implementation Options

* Using **Arrays**
* Using **Linked List**
* Using **STL (`queue`, `deque`, `priority_queue`) in C++**

---

## 🎯 When to Use Queue?

* Scheduling tasks (CPU scheduling)
* BFS traversal in graphs 🌐
* Handling requests (real-world systems)
* Buffering (IO operations)

---

## 🔥 Important Problems

* Implement Queue using Stack
* Circular Queue
* First Non-Repeating Character
* Sliding Window Maximum
* BFS Traversal

---

## ⚠️ Common Pitfalls

* Overflow (in array implementation)
* Underflow (dequeue on empty queue)
* Not handling circular indexing properly

---

## 💡 Key Insight

Queues are essential for **level-wise processing** and are heavily used in:

* Graph algorithms (BFS)
* Sliding window problems
* System design concepts

---

## 🧾 Notes

Queue may look simple, but mastering its variations (especially circular queue and deque) is crucial for solving many real-world and interview problems.
