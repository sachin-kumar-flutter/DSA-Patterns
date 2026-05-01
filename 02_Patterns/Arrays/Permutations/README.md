# 🔢 Permutation Patterns

> “Same elements, different arrangements — infinite possibilities.” ♾️

Master permutations through **backtracking, lexicographic tricks, and mathematical indexing** — a core pattern set for coding interviews.

---

## 🧠 Why Permutations Matter?

Permutation problems show up everywhere:

* Backtracking & recursion 🔁
* String rearrangements 🧵
* Combinatorics & math 🔢
* Interview puzzles with twists 🎯

If you understand permutations well, you unlock a **huge chunk of DSA**.

---

## ⚙️ Problem Categories

### 1️⃣ Generate All Permutations (Backtracking) 🔁

* Fix one element → recurse on rest
* Backtrack to explore all possibilities

💡 Foundation of recursion problems

---

### 2️⃣ Unique Permutations (Handling Duplicates) 🚫

* Avoid duplicate choices using:

  * Set (per recursion level) OR
  * Sorting + visited array

💡 Teaches pruning (very important skill)

---

### 3️⃣ Next / Previous Permutation 🔄

* Lexicographical ordering
* Find breakpoint → swap → reverse

💡 Used in:

* Next greater number
* Permutation transitions

---

### 4️⃣ K-th Permutation (Math-Based) 🔢

* Uses factorial number system
* Directly compute kth arrangement

💡 No brute force — pure logic

---

## 📂 Folder Structure

```bash id="a8e2s7"
permutation/
├── next_permutation.cpp
├── all_permutations_backtracking.cpp
├── unique_permutations.cpp
├── kth_permutation.cpp
```

---

## 🎯 Core Patterns Summary

| Type             | Technique       |
| ---------------- | --------------- |
| Generate all     | Backtracking    |
| Avoid duplicates | Pruning         |
| Next/Previous    | Lexicographic   |
| K-th permutation | Math + indexing |

---

## 🧩 Key Insights

* Fix one position → solve smaller problem
* Avoid bad paths early (pruning)
* Think in terms of **order, not just values**

---

## 🚀 Interview Cheat Line

> “Permutation problems are either backtracking, lexicographic transitions, or factorial indexing.”

Say this, and you instantly sound structured.

---

## ⚠️ Common Mistakes

* Generating duplicates ❌
* Forgetting backtracking step ❌
* Using brute force for kth permutation ❌

---

## 🔥 Real Talk

Most people just “generate permutations.”

Top candidates:

* Understand **why swapping works**
* Know **multiple approaches**
* Can optimize instantly

That’s the difference. ⚡

---

## 🏁 Final Thought

Permutation problems may look small…
but they build your thinking for:

> 👉 Recursion
> 👉 Optimization
> 👉 Pattern recognition

Master this once, reuse it forever.

---

⭐ If this helped you, consider starring the repo!
