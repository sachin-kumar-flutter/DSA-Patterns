# 🪟 Sliding Window Pattern

> "Why check all subarrays when you can slide smartly?" 🚀

---

## 📌 What is Sliding Window?

Sliding Window is an **optimized technique** used to process **subarrays / substrings** by maintaining a **window (range)** that moves across the array.

Instead of recalculating everything again and again (like brute force 😵), we:

* ➕ **Expand** the window (move `end`)
* ➖ **Shrink** the window (move `start`)
* 🎯 Maintain a **condition** (sum, length, distinct chars, etc.)

---

## 🧠 Core Idea

> Reuse previous computation instead of starting from scratch.

Think of it like:

* A window sliding over numbers
* You only update what changes, not everything

---

## 🔁 Types of Sliding Window

### 1️⃣ Fixed Size Window

* Window size is constant (`k`)
* Example:

  * Maximum sum of subarray of size `k`

🧩 Pattern:

```cpp
for (int i = 0; i < k; i++) sum += arr[i];

for (int i = k; i < n; i++) {
    sum += arr[i];        // add next
    sum -= arr[i - k];    // remove previous
}
```

---

### 2️⃣ Variable Size Window

* Window grows/shrinks based on condition

🧩 Pattern:

```cpp
while (end < n) {
    // expand
    add(arr[end]);

    while (condition satisfied) {
        // update answer
        // shrink
        remove(arr[start]);
        start++;
    }

    end++;
}
```

---

## 🔥 When to Use Sliding Window?

Ask yourself:

✅ Subarray / substring problem?
✅ Need **minimum / maximum length**?
✅ Condition involves **sum / count / distinct elements**?
✅ Brute force is O(n²)?

👉 Boom 💥 → Sliding Window likely works

---

## ⚡ Time Complexity

| Approach       | Complexity |
| -------------- | ---------- |
| Brute Force    | O(n²)      |
| Sliding Window | **O(n)**   |

💡 Each element is visited at most twice.

---

## 🧩 Common Problems

* ✅ Minimum Size Subarray Sum
* ✅ Longest Substring Without Repeating Characters
* ✅ Max Sum Subarray of Size K
* ✅ Binary Subarrays with Sum
* ✅ Longest Repeating Character Replacement

---

## 🚀 Key Insight

> Expand → satisfy condition → shrink → optimize answer

This **expand-shrink balance** is everything.

---

## 🧪 Pro Tips (Interview Gold 💎)

* Don’t blindly apply it ❌
* First identify:

  * Fixed or Variable window?
* Always track:

  * `start`, `end`, and **what condition breaks**
* Most mistakes happen while **shrinking the window**

---

## 🏁 Final Thought

Sliding Window is not just a trick —
it’s a mindset:

> "Do less work, but do it smarter." 😎

---

Happy Coding 💻🔥
