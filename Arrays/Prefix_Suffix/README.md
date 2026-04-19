# Prefix-Suffix

This section contains problems that use prefix and suffix computations to optimize repeated calculations.

---

## 🧠 Key Idea

Precompute results from:
- Left → **Prefix**
- Right → **Suffix**

So each query/result can be answered in **O(1)** after preprocessing.

---

## 🔑 Pattern

- `prefix[i]` → result from index `0 → i`
- `suffix[i]` → result from index `i → n-1`

---

## ⚙️ When to Use

Use this pattern when:
- You need **range-based information** (max, min, sum, product, etc.)
- Brute force leads to **nested loops (O(n²))**
- Each index depends on both **left and right side values**

---

## 📂 Problems

### 1. Product of Array Except Self
- Pattern: Prefix + Suffix
- Idea: Compute product of all elements except current without division
- Key Insight: Combine prefix product (left) and suffix product (right)

---

### 2. Smallest Stable Index I
- Pattern: Prefix Max + Suffix Min
- Idea: For each index `i`, check:

- Approach:
- Precompute prefix maximum array
- Precompute suffix minimum array
- Iterate to find the smallest valid index
- Time Complexity: **O(n)**
- Space Complexity: **O(n)** (can be optimized to O(1))

---

## 🎯 Why This Pattern is Important

- Eliminates redundant computations
- Converts **O(n²) → O(n)** problems
- Improves clarity in range-based logic
- Frequently asked in coding interviews (FAANG + service-based companies)

---

## 🚀 Pro Tip

Whenever you see:
- "left side + right side"
- "except self"
- "range max/min difference"

👉 Think **Prefix-Suffix immediately**
