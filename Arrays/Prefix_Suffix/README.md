# Prefix-Suffix

This section contains problems that use prefix and suffix computations to optimize repeated calculations.

## 🧠 Key Idea

Precompute results from left (prefix) and right (suffix) to avoid redundant work.

---

## 🔑 Pattern

- prefix[i] → result from start to i
- suffix[i] → result from i to end

---

## 📂 Problems

### Product of Array Except Self
- Pattern: Prefix + Suffix
- Idea: Compute product of all elements except current without division

---

## 🎯 Why Important?

- Eliminates need for nested loops
- Reduces time complexity
- Frequently asked interview problem
