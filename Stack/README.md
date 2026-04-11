# 🪵 Stack - Problem Solving Patterns

This section focuses on solving problems using the **Stack data structure**, emphasizing order-based processing and pattern recognition — widely used in interviews.

---

## 🧠 Core Concepts

* **LIFO (Last In First Out)**
  → The last inserted element is processed first

* **Monotonic Stack**
  → Maintain increasing/decreasing order in stack
  → Useful for next greater/smaller element problems

* **Expression Evaluation**
  → Evaluate infix, postfix, and prefix expressions
  → Handle operator precedence and parentheses

* **Simulation Using Stack**
  → Mimic real-world processes (undo, parsing, traversal)

---

## 🔑 Key Patterns Covered

### 🔹 Monotonic Stack

* Maintain a stack in sorted order
* Used for:

  * Next Greater Element
  * Next Smaller Element
  * Histogram / area problems

---

### 🔹 Expression & Parsing

* Convert and evaluate expressions
* Handle:

  * Parentheses
  * Operator precedence
  * Nested expressions

---

### 🔹 Stack-Based Simulation

* Simulate step-by-step processes
* Common in:

  * Valid parentheses
  * Browser history
  * Undo/redo operations

---

## 📂 Directory Structure

```bash id="3o7v2k"
Stack/
│
├── Monotonic_Stack/
│   └── Next greater/smaller element problems
│
├── Expression_Parsing/
│   └── Infix, postfix, prefix evaluation
│
├── Simulation/
│   └── Stack-based problem simulations
```

---

## 🎯 Why Stack?

* 📌 Essential for problems involving **order and structure**
* 📌 Key tool for **optimization and linear-time solutions**
* 📌 Frequently used in:

  * Parsing problems
  * Array optimizations
  * Expression evaluation

---

## ⚡ Key Takeaways

✔️ Stack helps convert nested or recursive logic into iterative form
✔️ Monotonic stack reduces complexity from O(n²) → O(n)
✔️ Always think about **order of processing**

---

## 🧠 Mental Model

When solving a problem, ask:

> 🔍 Do I need to remember previous elements?
> 🔍 Does order (next greater/smaller) matter?
> 🔍 Can I process elements while maintaining a condition?

---

## 🚀 Pro Tip

Whenever you see:

> “Next greater / smaller element” 👀

Think immediately:

> 🪵 Stack (Monotonic Stack)

---

🔥 **Control the order → Control the problem**
