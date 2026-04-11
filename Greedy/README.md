# 💰 Greedy Algorithms

This section focuses on building strong intuition for **greedy strategies** — one of the most elegant and efficient paradigms in algorithm design.

---

## 🧠 What is a Greedy Algorithm?

A greedy algorithm makes the **best local choice at each step**, aiming to achieve a **globally optimal solution**.

Unlike Dynamic Programming, greedy:

* ❌ Does **not revisit decisions**
* ⚡ Works only when:

  * **Optimal Substructure** exists
  * **Greedy Choice Property** holds

---

## 🔍 When to Think Greedy?

Look for these signals:

* 📈 You need to **maximize / minimize** something
* 🔗 Choices appear **independent at each step**
* 🔄 Sorting or ordering simplifies decisions
* 🚫 Once chosen, decisions **don’t need to be undone**

---

## 🔑 Key Patterns Covered

### 1. 👣 Two Pointers + Greedy Matching

* Efficient pairing under constraints
* Common in interval and distance-based problems

---

### 2. 🔃 Sorting + Optimal Pairing

* Sort input to simplify decision-making
* Classic trick: **pair smallest with largest**

---

### 3. 🔁 Reverse Processing (Think Backwards)

* Process from the end when later operations override earlier ones
* Eliminates redundant work

---

### 4. 🧩 Greedy + Structure Awareness

* Limited valid configurations → constant-time decisions
* Often combined with hashing or fixed patterns

---

## 📂 Problems Included

### 📌 Minimize Maximum Pair Sum

* **Pattern:** Greedy + Two Pointers
* **Idea:** Pair smallest with largest
* **Insight:** Balances extremes to minimize maximum

---

### 📌 Police and Thieves

* **Pattern:** Greedy + Two Pointers
* **Idea:** Match nearest valid pairs
* **Insight:** Local optimal matches maximize total matches

---

### 📌 Sum of Matrix After Queries

* **Pattern:** Greedy + Reverse Processing
* **Idea:** Process queries from the end
* **Insight:** Only last updates matter

---

### 📌 Maximum Number of Families (Cinema Seating)

* **Pattern:** Greedy + Structure Awareness
* **Idea:** Check fixed seating blocks
* **Insight:** Limited valid configurations simplify decisions

---

## 🎯 Why These Problems?

These problems are selected to:

* Build **strong greedy intuition**
* Highlight **real interview patterns**
* Teach when greedy **works vs fails**

---

## ⚡ Common Mistakes

* ❌ Assuming greedy works without proof
* ❌ Ignoring constraints and edge cases
* ❌ Not verifying the **greedy choice property**

---

## 🧩 Greedy vs Dynamic Programming

| Greedy                               | Dynamic Programming        |
| ------------------------------------ | -------------------------- |
| Fast & simple                        | More flexible              |
| No backtracking                      | Explores all possibilities |
| Works only under specific conditions | Works for broader problems |

---

## 🚀 Key Takeaway

Greedy works when:

* A **local optimal choice guarantees global optimality**
* Decisions are **final and irreversible**
* Problem structure supports **step-by-step optimization**

---

## 🧠 Mental Model

When solving a problem, ask:

> 🔍 Can I sort the input to simplify decisions?
> 🔍 Can I make a choice that I’ll never regret later?
> 🔍 Does picking the best now guarantee the best overall?

---

## 📌 Pro Tip

> "If it feels too simple — just pick the best option each time…"

👉 It’s either a **greedy problem… or a trap** 😄

Train your intuition by solving more patterns here.

---

🔥 **Greedy is not about being lucky — it's about being logically confident**
