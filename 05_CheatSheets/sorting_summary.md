# 🔢 Sorting Summary

A quick guide to choose the **right sorting algorithm** based on constraints.

---

## ⚡ Core Idea

👉 Sorting is often the **first step** to simplify problems.

---

## 🚀 Comparison Table

| Algorithm      | Time Complexity   | Space    | Stable | Notes                          |
| -------------- | ----------------- | -------- | ------ | ------------------------------ |
| Bubble Sort    | O(n²)             | O(1)     | ✅      | Rarely used                    |
| Selection Sort | O(n²)             | O(1)     | ❌      | Simple but inefficient         |
| Insertion Sort | O(n²) / O(n) best | O(1)     | ✅      | Good for small / nearly sorted |
| Merge Sort     | O(n log n)        | O(n)     | ✅      | Stable, predictable            |
| Quick Sort     | O(n log n) avg    | O(log n) | ❌      | Fastest in practice            |
| Heap Sort      | O(n log n)        | O(1)     | ❌      | Based on heap                  |

---

## 🎯 When to Use What?

* Small input / nearly sorted → **Insertion Sort**
* Guaranteed performance → **Merge Sort**
* Fast average case → **Quick Sort**
* Memory constraint → **Heap Sort**

---

## 🔥 Key Concepts

* Stability → Preserves order of equal elements
* In-place → Uses constant extra space
* Divide & Conquer → Merge Sort, Quick Sort

---

## ⚠️ Common Pitfalls

* Ignoring worst-case (Quick Sort → O(n²))
* Choosing wrong algorithm for constraints
* Forgetting stability in problems

---

## 💡 Key Insight

👉 Sorting is not the goal—it’s a **tool to unlock simpler solutions**.

---

## 🧾 Final Tip

If stuck in a problem:

* Try sorting first
* Then apply patterns like:

  * Two Pointers
  * Binary Search
  * Greedy

---

Master sorting → simplify problems → think faster 🚀
