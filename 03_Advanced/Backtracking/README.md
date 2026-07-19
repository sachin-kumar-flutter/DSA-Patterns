# 🚀 Advanced Backtracking

> *"Simple recursion generates possibilities. Advanced backtracking eliminates impossibilities."* ⚡

Backtracking is DFS with a conscience — it explores a choice, and the moment it senses a dead end, it **undoes itself and tries again**. No brute force, no wasted paths, just smart elimination. 🧠

This folder is a curated set of problems that go beyond textbook recursion into real constraint-satisfaction territory: heavy pruning 🌳, constraint checking 🧩, and state restoration ♻️.

---

## 📂 What's Inside

| # | Problem | Core Idea | Pruning Technique | Time Complexity |
|---|---------|-----------|-------------------|------------------|
| 1️⃣ | [`nQueens.cpp`](./nQueens.cpp) | Place N queens with zero attacks | Diagonal bitmask hashing 🎯 | `O(N!)` |
| 2️⃣ | [`sudoku_solver.cpp`](./sudoku_solver.cpp) | Fill 9×9 grid respecting row/col/box rules | Constraint validity check 🔍 | `O(9^m)` |
| 3️⃣ | [`word_search.cpp`](./word_search.cpp) | Find a word hidden in a grid | Grid DFS + visited marking 🧵 | `O(N·M·4^L)` |

---

## 🧩 Why These Problems?

Each one teaches a different flavor of backtracking:

- **N-Queens** 👑 → row-by-row decision making, where the trick is representing constraints (columns + both diagonals) as compact bitmasks instead of brute-force scanning.
- **Sudoku Solver** 🔢 → cell-by-cell decision making with three overlapping constraints (row, column, box) that must all hold simultaneously.
- **Word Search** 🔤 → path-based backtracking on a grid, where "undoing a choice" means unmarking a visited cell so other paths can reuse it.

Different shapes, same skeleton:

```
solve(state):
    if goal reached → done ✅
    for each choice:
        if valid:
            make choice 🟢
            if solve(next state) → propagate success
            undo choice 🔴
    return false / continue
```

---

## 🛠️ Tech Stack

- Language: **C++**
- Paradigm: Recursive backtracking + bitmask optimization
- Focus: Correctness first, then pruning for performance ⚙️

---

## 📈 Progress Tracker

- [x] N-Queens (optimized with diagonal hashing)
- [x] Sudoku Solver
- [x] Word Search
- [ ] Rat in a Maze 🐭
- [ ] Combination Sum 🧮
- [ ] Palindrome Partitioning ✂️

---

### 🔗 Part of the [DSA-Patterns](../../) repository

⭐ If this helped you understand backtracking better, consider starring the repo!
