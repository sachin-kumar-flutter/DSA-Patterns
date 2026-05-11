# 🔥 Backtracking Patterns

> “Backtracking is not guessing randomly.
> It is exploring possibilities intelligently.” 🧠

Backtracking is one of the most important problem-solving techniques in DSA.

The core idea is simple:

```text id="z4v9xe"
Choose → Explore → Undo
```

At every step:

* make a choice
* explore recursively
* backtrack and try another path

---

# 🧠 What This Section Covers

This folder contains the most important backtracking patterns used in coding interviews:

* subset generation 📦
* duplicate pruning 🚫
* permutations 🔄
* target combinations 🎯
* recursive partitioning ✂️

---

# 📂 Problems Included

```bash id="6v5qqs"
Backtracking/
├── subsets.cpp
├── subsets_2.cpp
├── combination_sum.cpp
├── combination_sum_2.cpp
├── permutations.cpp
├── permutations_2.cpp
├── palindrome_partitioning.cpp
```

---

# 🔥 Core Backtracking Patterns

| Pattern                | Problem                 |
| ---------------------- | ----------------------- |
| Include / Exclude      | Subsets                 |
| Duplicate Pruning      | Subsets II              |
| Reuse Elements         | Combination Sum         |
| Unique Combinations    | Combination Sum II      |
| Arrangement Generation | Permutations            |
| Unique Arrangements    | Permutations II         |
| Recursive Partitioning | Palindrome Partitioning |

---

# ⚙️ Standard Backtracking Template

```cpp id="zscv6y"
void solve(...) {

    // base case

    for(...) {

        // choose

        solve(...);

        // backtrack
    }
}
```

---

# 💡 The Most Important Insight

Backtracking is basically:

# 🌳 Decision Tree Exploration

Every recursion call creates:

* a new choice
* a new branch
* a new state

The goal is to:

```text id="5i0r8n"
explore valid paths efficiently
```

---

# 🔥 Common Techniques Used

## 🚫 Duplicate Pruning

```cpp id="4x0t1s"
if(i > idx && nums[i] == nums[i - 1])
```

Used in:

* Subsets II
* Combination Sum II
* Permutations II

---

## 🎯 Target Reduction

```cpp id="8m3m0o"
target - candidates[i]
```

Used in:

* Combination Sum

---

## 🔄 Visited Array

```cpp id="5phm9h"
vector<bool> visited
```

Used in:

* Permutations

---

# ⚠️ Common Mistakes

* Forgetting backtracking step ❌
* Wrong recursion boundaries ❌
* Duplicate combinations/permutations ❌
* Missing base cases ❌

---

# 🧠 What Backtracking Really Teaches

Backtracking improves:

* recursion intuition 🌳
* state-space exploration 🔍
* pruning invalid paths ⚡
* decision-based thinking 🎯

---

# 🚀 Interview Insight

Most backtracking problems are NOT about memorizing code.

They are about answering:

```text id="w6r2yx"
“What choices can I make from here?”
```

That’s the real mindset.

---

# 🏁 Final Thought

The goal is not:

> “Generate all possibilities slowly.”

The goal is:

> “Explore only meaningful possibilities efficiently.” 🔥

---

⭐ If this helped, consider starring the repo!
