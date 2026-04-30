# 🧱 Monotonic Stack

A **monotonic stack** is a special stack that maintains elements in a strictly **increasing 📈** or **decreasing 📉** order.

It helps reduce brute-force O(n²) problems to **O(n)** by ensuring each element is pushed and popped at most once.

---

## 🔑 Core Pattern

- Maintain a stack in sorted order (increasing/decreasing)
- Process elements in one pass
- Pop elements when the current element violates monotonicity
- Use indices instead of values when position matters

---

## 🎯 When to Use

Use monotonic stack when:
- 🔍 You need **next greater / smaller element**
- 📏 You need **nearest greater/smaller to left/right**
- ⚡ You want to optimize from **O(n²) → O(n)**
- 📊 Range queries or span-based problems are involved

---

## 🧠 Types of Monotonic Stack

### 📈 Increasing Stack
- Stack top is always smaller
- Used for **next smaller element**

### 📉 Decreasing Stack
- Stack top is always greater
- Used for **next greater element**

---

## 📂 Problems

### 🌡️ Daily Temperatures  
👉 Find next warmer day using decreasing stack  

### 📊 Largest Rectangle in Histogram  
👉 Use increasing stack to calculate width efficiently  

### 🧱 Maximal Rectangle  
👉 Extension of histogram problem in 2D  

### ✂️ Remove K Digits  
👉 Greedy + monotonic increasing stack  

### 🔗 Next Greater Node In Linked List  
👉 Convert linked list to array + apply monotonic decreasing stack  
👉 Classic **Next Greater Element to the right** variation  

---

## ⚡ Key Takeaways

- Each element is processed **at most twice** (push + pop) → O(n)
- Always think:
  > “Can I maintain a useful order while scanning once?”

- Monotonic stack is not about stack — it’s about **controlled removal of useless elements**

---

## 🚀 Pro Insight

Most problems reduce to:

> “Find the first element that breaks monotonicity”

Once you see that, the solution almost writes itself.

---

## 🧩 Pattern Family

If you master this, you automatically get:

- Next Greater Element I & II  
- Daily Temperatures  
- Stock Span Problem  
- Trapping Rain Water (variant thinking)  
- Sum of Subarray Minimums  

---

🔥 **Rule of thumb:**  
If you’re thinking *“for every element, I need to check ahead”* →  
Stop. Use a monotonic stack.
