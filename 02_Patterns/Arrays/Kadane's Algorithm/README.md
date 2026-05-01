# ⚡ Kadane’s Algorithm (Subarray Patterns)

> “At every step: start fresh… or keep going.” 🔁

Kadane’s Algorithm is a powerful pattern to solve **maximum (or minimum) subarray problems in linear time**. It blends **greedy intuition with dynamic programming**.

---

## 🧠 Why Kadane’s Matters?

You’ll see this pattern everywhere:

* Maximum subarray sum 📈
* Maximum product subarray 🔄
* Circular subarray problems 🔁
* Many DP optimizations ⚙️

If you understand Kadane’s deeply, you unlock a **huge class of array problems**.

---

## ⚙️ Core Idea

At each index, decide:

👉 **Start a new subarray OR extend the previous one**

That’s it.

---

## 📌 Standard Form (Maximum Sum)

```text id="std-kadane"
curr = max(arr[i], curr + arr[i])
ans  = max(ans, curr)
```

💡 You’re always choosing the better option:

* Start fresh from `arr[i]`
* Or extend the current streak

---

## 🔄 Variations Covered

### 1️⃣ Maximum Subarray Sum ⭐

* Classic Kadane
* Handles negative values

---

### 2️⃣ Maximum Product Subarray ⭐⭐

* Track both **max and min**
* Negative numbers can flip results

---

### 3️⃣ Maximum Circular Subarray ⭐⭐⭐

* Combine:

  * Normal Kadane
  * Min subarray logic

💡 Formula:

```text id="circular-formula"
maxCircular = totalSum - minSubarray
```

---

## 📂 Folder Structure

```bash id="kadane-structure"
kadane/
├── maximum_subarray.cpp
├── maximum_product_subarray.cpp
├── maximum_circular_subarray.cpp
```

---

## 🎯 Pattern Summary

| Problem      | Trick                 |
| ------------ | --------------------- |
| Max sum      | Track max ending here |
| Max product  | Track max + min       |
| Circular sum | total - min subarray  |
| Min subarray | Reverse Kadane        |

---

## ⚠️ Common Pitfalls

* Initializing `curr = 0` ❌
* Failing on all-negative arrays ❌
* Ignoring negative flips (product case) ❌

---

## 🚀 Interview Cheat Line

> “At each index, I decide whether to start a new subarray or extend the previous one using Kadane’s algorithm.”

Simple. Powerful. Effective.

---

## 🧩 Related Problems

* Maximum Subarray
* Maximum Product Subarray
* Maximum Sum Circular Subarray

---

## 🔥 Real Insight

Kadane’s is not just about sums.

It teaches you:

> 👉 Local decision → Global optimum
> 👉 When to reset vs continue
> 👉 How to optimize brute force

---

## 🏁 Final Thought

Most people memorize Kadane’s.

Top candidates understand:

* **Why it works**
* **When it breaks**
* **How to extend it**

That’s the real difference. ⚡

---

⭐ If this helped you, consider starring the repo!
