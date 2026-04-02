# Prefix Sum 

This section contains problems that use prefix sum techniques to efficiently compute range queries and submatrix sums.

## 🧠 What is Prefix Sum?

Prefix sum is a technique used to preprocess data so that range queries can be answered in constant time.

For arrays:
- prefix[i] = sum of elements from index 0 to i-1

For matrices:
- prefix[i][j] stores sum of submatrix from (0,0) to (i-1,j-1)

---

## 🔑 Key Patterns Covered

- 1D Prefix Sum (range sum queries)
- 2D Prefix Sum (submatrix queries)
- Prefix Sum + Binary Search
- Prefix Sum + Brute Force Optimization

---

## 📂 Problems Included

### 1. Largest Magic Square
- Pattern: Prefix Sum + Validation
- Idea: Use prefix sums to efficiently check row and column sums

### 2. Maximum Side Length of Square ≤ Threshold
- Pattern: Prefix Sum + Binary Search
- Idea: Use prefix sum for fast area calculation and binary search for optimal size

---

## 🎯 Why Prefix Sum?

- Converts repeated O(n) computations into O(1)
- Essential for optimizing brute-force solutions
- Widely used in matrix and range query problems

---

## ⚡ Key Takeaway

Use prefix sum when:
- Multiple range sum queries are involved
- You need fast subarray or submatrix computations
- Brute force is too slow due to repeated summation
