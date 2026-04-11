# 📊 Prefix Sum

This section contains problems that use **prefix sum techniques** to efficiently compute range queries and submatrix sums.

---

## 🧠 What is Prefix Sum?

Prefix sum is a preprocessing technique that allows you to answer **range sum queries in O(1)** time.

### 📌 1D Array:
- `prefix[i] = sum of elements from index 0 to i-1`

### 📌 2D Matrix:
- `prefix[i][j] = sum of submatrix from (0,0) to (i-1,j-1)`

---

## 🔑 Key Patterns Covered

✨ 1D Prefix Sum → Range sum queries  
✨ 2D Prefix Sum → Submatrix queries  
✨ Prefix Sum + HashMap → Subarray problems (sum = 0 / K)  
✨ Prefix Sum + Binary Search → Optimization problems  
✨ Prefix Sum + Sliding Window Insight → Hybrid problems  

---

## 📂 Problems Included

### 🟢 1. Count Subarrays with Sum = 0
- Pattern: Prefix Sum + HashMap  
- 💡 Idea: If same prefix sum appears again → subarray sum = 0  

---

### 🔵 2. Count Subarrays with Sum = K
- Pattern: Prefix Sum + HashMap  
- 💡 Idea: Check if `(prefixSum - k)` exists  

---

### 🟡 3. Largest Magic Square
- Pattern: Prefix Sum + Validation  
- 💡 Idea: Use prefix sums to quickly verify row & column sums  

---

### 🟠 4. Maximum Side Length of Square ≤ Threshold
- Pattern: Prefix Sum + Binary Search  
- 💡 Idea: Use prefix sum for fast area calculation + binary search for size  

---

## 🎯 Why Prefix Sum?

🚀 Converts repeated O(n) work → **O(1)** queries  
⚡ Reduces brute force complexity significantly  
📦 Extremely useful in arrays, matrices & subarray problems  

---

## 🧠 When to Use Prefix Sum?

Use it when:
- 🔁 Multiple range sum queries  
- 📊 Subarray / submatrix computations  
- ⚠️ Negative numbers present (sliding window may fail)  
- 🔍 Counting subarrays with specific sum  

---

## ⚡ Key Takeaways

💡 Same prefix sum ⇒ subarray sum = 0  
💡 `(prefixSum - k)` ⇒ subarray sum = k  
💡 Always initialize `map[0] = 1` in hashmap problems  

---

## 🧩 Pro Tip

> If sliding window fails due to negative numbers → switch to Prefix Sum + HashMapto Prefix Sum + HashMap
