# 🔄 Array Rotation

Rotate smarter, not harder 😎

This directory contains efficient in-place algorithms to rotate an array by `d` positions.  
Both approaches achieve optimal performance with **O(n) time** and **O(1) space**.

---

## 🚀 Approaches Implemented

### 🔁 1. Reversal Algorithm
> Flip. Flip. Flip. Done.

- Reverse first `d` elements  
- Reverse remaining `n-d` elements  
- Reverse the whole array  

✨ Simple and interview-friendly  
✨ Clean logic, easy to debug  

---

### 🔄 2. Juggling Algorithm
> Move elements in cycles using math 🧠

- Based on **GCD(n, d)**  
- Divides array into independent cycles  
- Rotates elements within each cycle  

✨ More mathematical approach  
✨ Shows deeper understanding  

---

## ⚔️ Quick Comparison

| Approach   | Idea                | Difficulty | Best Use Case        |
|-----------|--------------------|-----------|---------------------|
| Reversal  | Reverse segments   | Easy ⭐     | Interviews          |
| Juggling  | Cyclic movement    | Medium ⭐⭐  | Concept mastery     |

---

## ⏱️ Complexity

- **Time:** O(n)  
- **Space:** O(1) (In-place)

---

