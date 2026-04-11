# 📊 Monotonic Segments Pattern

## 🔹 What is this pattern?

The **Monotonic Segments Pattern** involves breaking an array into **continuous segments** where a certain property (increasing, decreasing, equal, etc.) holds true.

Instead of analyzing all subarrays individually, we:

* Identify valid segments
* Process each segment mathematically

---

## 🔹 Core Idea

If a segment satisfies a condition and has length `k`, then:

* Total subarrays inside that segment = `k * (k - 1) / 2`

This avoids nested loops and reduces time complexity from **O(n²) → O(n)**.

---

## 🔹 When to use this pattern?

Use this approach when:

* The problem involves **continuous sequences**
* Conditions depend on **relative comparison** (>, <, ==)
* You need to count subarrays or lengths efficiently
* The array can be divided into **independent segments**

---

## 🔹 Common Examples

* Count strictly increasing subarrays
* Count strictly decreasing subarrays
* Longest increasing subarray
* Maximum consecutive ones
* Count subarrays with equal elements

---

## 🔹 General Approach

1. Initialize `count = 1`
2. Traverse the array
3. If condition holds → extend segment (`count++`)
4. Else:

   * Process previous segment
   * Reset `count = 1`
5. Process last segment

---

## 🔹 Complexity

* ⏱ Time: O(n)
* 🧠 Space: O(1)

---

## 🔹 Why this pattern matters?

* Frequently asked in interviews
* Builds strong intuition for array traversal
* Foundation for advanced patterns like:

  * Sliding Window
  * Two Pointers
  * Greedy segmentation

---

## 🔹 Problems in this directory

* Increasing Subarray Count

---

## 🚀 Pro Tip

Whenever you see:

> "continuous", "increasing", "decreasing", "consecutive"

Think:
👉 **Can I break this into segments?**
