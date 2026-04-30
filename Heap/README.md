# ⚡ Heap (Priority Queue) – Master the Top Elements Game

Welcome to the **Heap** section of my DSA journey 🚀
This folder contains problems where we efficiently manage elements based on priority using heaps.

---

## 🧠 What is a Heap?

A **Heap** is a special tree-based data structure that satisfies the heap property:

* 🔼 **Max Heap** → Parent ≥ Children (Top = largest element)
* 🔽 **Min Heap** → Parent ≤ Children (Top = smallest element)

In C++, we use `priority_queue` to implement heaps effortlessly.

---

## 💡 Why Heaps?

Heaps shine when you need to:

* 🏆 Find **kth largest/smallest** elements
* ⚡ Maintain **top K elements efficiently**
* 🔄 Handle **dynamic data streams**
* 📊 Solve problems involving **priority-based processing**

---

## 📂 Problems Covered

### 🔹 Kth Largest Element in an Array

* 🧩 Approach 1: **Max Heap**

  * Time: `O(n log n)`
  * Simple and intuitive

* 🧩 Approach 2: **Min Heap (Optimized)**

  * Time: `O(n log k)`
  * Best for large inputs 🔥

---

## 🚀 Key Takeaways

* Default `priority_queue` in C++ is a **Max Heap**
* Use `greater<T>` to convert it into a **Min Heap**
* Heaps are not just theory — they are **interview weapons** 💣

---

## 📌 Pro Tip

If you're solving **kth element problems**:

> 👉 Always think: "Can I reduce complexity using a heap of size k?"

---

## 🏁 What's Next?

More heap-based problems coming soon:

* Median in Data Stream 📈
* Merge K Sorted Lists 🔗
* Top K Frequent Elements 🔝

Stay tuned… this folder is just getting started 😄
