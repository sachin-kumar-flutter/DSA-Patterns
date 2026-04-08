# 🟢 Greedy Algorithms

This section contains carefully curated problems that showcase the power, intuition, and patterns behind **greedy strategies** — one of the most elegant paradigms in algorithm design.

---

## 🧠 What is a Greedy Algorithm?

A greedy algorithm makes the **best possible local choice at each step**, with the hope that these choices lead to a **globally optimal solution**.

Unlike dynamic programming, greedy solutions:

* Do **not revisit decisions**
* Work when the problem has **optimal substructure + greedy choice property**

---

## 🔍 When to Think Greedy?

Look for these signals:

* You are asked to **maximize/minimize** something
* Choices look **independent at each step**
* Sorting or ordering helps simplify decisions
* Once a choice is made, it **does not need to be undone**

---

## 🔑 Key Patterns Covered

### 1. Two Pointers + Greedy Matching

* Efficient pairing based on constraints
* Often used in interval or distance-based problems

### 2. Sorting + Optimal Pairing

* Sort input to make optimal decisions easier
* Common trick: **pair extremes (min + max)**

### 3. Reverse Processing (Thinking Backwards)

* Process from the end when future operations override past ones
* Helps eliminate unnecessary work

---

## 📂 Problems Included

### 1. Minimize Maximum Pair Sum

* **Pattern:** Greedy + Two Pointers
* **Idea:** Pair smallest with largest to balance sums
* **Insight:** Prevents large values from dominating the result

---

### 2. Police and Thieves

* **Pattern:** Greedy + Two Pointers
* **Idea:** Match nearest valid policeman–thief pairs
* **Insight:** Local nearest match ensures maximum total matches

---

### 3. Sum of Matrix After Queries

* **Pattern:** Greedy + Reverse Processing
* **Idea:** Process queries from the end since only last updates matter
* **Insight:** Avoid redundant updates by leveraging order

---

### 4. Maximum Number of Families (Cinema Seating)

* **Pattern:** Greedy + Hashing
* **Idea:** Check fixed seating blocks per row ([2–5], [4–7], [6–9])
* **Insight:** Only limited valid configurations → constant-time decisions per row

---

## 🎯 Why These Problems?

These problems are selected to:

* Build **strong greedy intuition**
* Highlight **real interview patterns**
* Teach how to identify when greedy **works vs fails**

---

## ⚡ Common Mistakes in Greedy

* Assuming greedy works without proof
* Ignoring edge cases (like overlaps or constraints)
* Not verifying the **greedy choice property**

---

## 🧩 Greedy vs Dynamic Programming

| Greedy                          | Dynamic Programming        |
| ------------------------------- | -------------------------- |
| Fast & simple                   | More flexible              |
| No backtracking                 | Explores all possibilities |
| Works only when conditions hold | Works for broader problems |

---

## 🚀 Key Takeaway

Greedy works when:

* A **local optimal choice guarantees global optimality**
* Decisions are **final and irreversible**
* The problem structure naturally supports **step-by-step optimization**

---

## 📌 Pro Tip

If you ever feel:

> "This looks too simple… just pick the best option each time?"

👉 That’s either a **greedy problem… or a trap** 😄
Train your intuition by solving more patterns in this section.

---
