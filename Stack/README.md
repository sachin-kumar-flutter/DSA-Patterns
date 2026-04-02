# 📚 Stack Patterns

This folder contains all important **Stack-based problems and patterns** commonly asked in coding interviews (especially for product-based companies and GATE-level understanding).

---

## 🧠 What is a Stack?

A Stack is a **Last In First Out (LIFO)** data structure.

### Basic Operations:
- `push()` → insert element
- `pop()` → remove top element
- `top()/peek()` → get top element
- `empty()` → check if stack is empty

---

## ⚡ When to Use Stack?

Use stack when:
- You need to **track previous elements**
- Problems involve **nested structures** (parentheses, expressions)
- You need **monotonic behavior** (increasing/decreasing)
- You process elements in **reverse or order-sensitive way**

---

# 📂 Folder Structure & Patterns

---

## 1️⃣ Basic Stack

📁 `Basic_Stack/`

### 📌 Covers:
- Stack implementation
- Valid parentheses
- Basic push/pop logic

### 💡 Key Idea:
Understand how stack behaves and builds intuition.

### 🧾 Problems:
- Implement Stack
- Valid Parentheses
- Next Greater Element (basic)

---

## 2️⃣ Monotonic Stack

📁 `Monotonic_Stack/`

### 📌 Covers:
- Next Greater Element (NGE)
- Next Smaller Element (NSE)
- Previous Greater/Smaller
- Histogram problems

### 💡 Key Idea:
Maintain a stack that is:
- Increasing OR
- Decreasing

### 🚀 Why Important?
Used in:
- Largest Rectangle in Histogram
- Stock Span
- Daily Temperatures

### ⏱ Complexity:
- Time: **O(n)**
- Each element pushed/popped once

---

## 3️⃣ Expression Parsing

📁 `Expression_Parsing/`

### 📌 Covers:
- Infix → Postfix
- Infix → Prefix
- Postfix Evaluation
- Reverse Polish Notation

### 💡 Key Idea:
Use stack to:
- Handle operator precedence
- Manage parentheses
- Evaluate expressions

### 🧾 Problems:
- Evaluate Reverse Polish Notation
- Infix to Postfix Conversion

---

## 4️⃣ Stack Simulation

📁 `Stack_Simulation/`

### 📌 Covers:
Problems where stack is used to simulate real-world processes.

### 💡 Key Idea:
Stack helps in:
- Undo operations
- Backtracking
- Sequential simulation

### 🧾 Problems:
- Asteroid Collision
- Baseball Game
- Simplify Path

---

# 🔥 Common Patterns Summary

| Pattern              | Use Case                          |
|---------------------|----------------------------------|
| Basic Stack         | Parentheses, simple tracking     |
| Monotonic Stack     | Next greater/smaller problems    |
| Expression Parsing  | Expression evaluation            |
| Simulation          | Process-based problems           |

---

# ⚠️ Mistakes to Avoid

- ❌ Forgetting to check `stack.empty()`
- ❌ Wrong order of push/pop
- ❌ Ignoring edge cases (empty input)
- ❌ Not understanding monotonic condition

---

# 🧠 Interview Tips

- Always explain:
  > “I am using stack to keep track of previous elements…”

- For monotonic stack:
  > “Each element is pushed and popped once → O(n)”

- For parsing:
  > “Stack helps manage operator precedence and parentheses”

---

# 🚀 Final Thoughts

Stack is not just a data structure —  
it’s a **thinking pattern**.

Master these patterns and you’ll:
- Solve problems faster
- Recognize patterns instantly
- Perform better in interviews

---

⭐ Tip: Revise this folder multiple times — Stack patterns are HIGHLY repetitive in interviews.
