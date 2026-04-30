# 📊 Prefix Sum Pattern

> "Precompute once, answer infinitely fast." ⚡

---

## 📌 What is Prefix Sum?

Prefix Sum is a technique where we **precompute cumulative sums** so that any subarray sum can be calculated in **O(1)** time.

Instead of recalculating sums again and again:

* ❌ Brute force → O(n²)
* ✅ Prefix Sum → O(n)

---

## 🧠 Core Idea

Create an array where:

```cpp id="8c0kqf"
prefix[i] = sum of elements from index 0 to i
```

Then any subarray sum from `L → R` is:

```cpp id="k4wr8m"
sum = prefix[R] - prefix[L - 1]
```

💡 That’s it. That one line saves you from nested loops 😎

---

## 🔁 Types of Prefix Sum Usage

### 1️⃣ Basic Prefix Sum

* Direct sum queries on subarrays

---

### 2️⃣ Prefix Sum + HashMap 🧠🔥

* Used when:

  * Counting subarrays
  * Detecting patterns like sum = K, sum = 0

---

### 3️⃣ 2D Prefix Sum 🧩

* For matrices
* Fast area / square / rectangle sum queries

---

### 4️⃣ Prefix Sum + Binary Search 🚀

* When answer depends on size/length
* Combine fast sum queries + search space optimization

---

## ⚡ Time Complexity

| Task               | Complexity |
| ------------------ | ---------- |
| Build Prefix Array | O(n)       |
| Query Subarray Sum | O(1)       |
| With HashMap       | O(n)       |

---

## 📂 Problems Included

---

### 🟢 Count Subarrays with Sum = 0

**Pattern:** Prefix Sum + HashMap

💡 **Idea:**
If the same prefix sum appears again → the elements in between sum to **0**

👉 Because:

```cpp id="m4h6o0"
prefix[j] - prefix[i] = 0
```

---

### 🔵 Count Subarrays with Sum = K

**Pattern:** Prefix Sum + HashMap

💡 **Idea:**
Check if:

```cpp id="x0k9d2"
(prefixSum - k)
```

exists before

👉 If yes → valid subarray found

---

### 🟡 Largest Magic Square

**Pattern:** Prefix Sum + Validation

💡 **Idea:**
Use prefix sums to quickly:

* Check row sums
* Check column sums

👉 Avoid recomputing each time

---

### 🟠 Maximum Side Length of Square ≤ Threshold

**Pattern:** Prefix Sum + Binary Search

💡 **Idea:**

* Use prefix sum → fast square sum calculation
* Use binary search → find max valid size

👉 Best combo: **Speed + Optimization**

---

## 🔥 When to Use Prefix Sum?

Ask yourself:

✅ Need fast subarray sum queries?
✅ Multiple range queries?
✅ Counting subarrays with conditions?
✅ Matrix / grid sum problems?

👉 Prefix Sum is your weapon ⚔️

---

## 🧪 Pro Tips (Interview Gold 💎)

* Always think:

  > "Can I precompute something to avoid repeated work?"

* For counting problems:

  * Use **HashMap with prefix sum**

* For grids:

  * Think **2D prefix sum immediately**

* For optimization:

  * Combine with **Binary Search**

---

## 🚀 Key Insight

> Prefix Sum turns repeated work into instant answers.

It’s not just an array —
it’s **precomputation power** 💪

---

## 🏁 Final Thought

Sliding Window moves forward.
Prefix Sum remembers the past.

> And in DSA, memory is power. 🧠⚡

---

Happy Coding 💻🔥
