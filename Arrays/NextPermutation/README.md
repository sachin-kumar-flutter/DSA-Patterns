# 🔢 Next Permutation — C++ 🚀

> Transform your array into the **next lexicographically greater permutation** — or reset it to the smallest if you're already at the top 😉

---

## 🧩 Problem Statement

Given an array of integers, rearrange it into the **next permutation** in lexicographical order.

* If such arrangement is **not possible** (i.e., array is in descending order),
  👉 rearrange it to the **lowest possible order (ascending)**.

---

## 🧠 Intuition (The Real Trick)

We don’t want *just any* bigger permutation…
We want the **smallest possible increase** 🔥

So the plan is:

1. Find where the increasing order breaks
2. Swap smartly
3. Fix the remaining part

---

## ⚙️ Approach (3-Step Magic ✨)

### 1️⃣ Find the Breakpoint

Traverse from right → left and find the first index `i` such that:

```
nums[i] < nums[i+1]
```

---

### 2️⃣ Find Just Greater Element

From the right, find element `j` such that:

```
nums[j] > nums[i]
```

Swap them 🔄

---

### 3️⃣ Reverse the Suffix

Reverse elements from `i+1 → end`
👉 This ensures the **smallest possible order**

---

## 🧪 Example

### Input:

```
1 2 5 4 3
```

### Output:

```
1 3 2 4 5
```

---

## 🚨 Edge Case

### When array is descending:

```
5 4 3 2 1
```

### Output:

```
1 2 3 4 5
```

---

## ⏱️ Complexity

| Type     | Value |
| -------- | ----- |
| 🕒 Time  | O(N)  |
| 📦 Space | O(1)  |

---

## 💻 STL Shortcut (But Know the Logic 😉)

```cpp
next_permutation(nums.begin(), nums.end());
```

---

## 🎯 Key Insight

> We generate the next permutation by making the **smallest possible increase** in the sequence.

---

## 🏷️ Tags

`Arrays` `Permutations` `Greedy` `Interview-Favorite`

---

## ⭐ Why This Problem Matters

* Frequently asked in **coding interviews**
* Tests **pattern recognition + greedy thinking**
* Builds foundation for **advanced permutation problems**

---

## 🚀 Future Additions (Coming Soon...)

* Previous Permutation 🔁
* K-th Permutation 🔢
* All Permutations (Backtracking) 🌳

---

### 💬 Final Thought

> “Small changes make the next big thing.” — literally what this problem teaches 😄

---
