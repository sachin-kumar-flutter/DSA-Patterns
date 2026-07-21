# 🔄 Kosaraju's Algorithm

> Identify groups of vertices where **every vertex is reachable from every other vertex** using two elegant DFS traversals.

Kosaraju's Algorithm is a DFS-based algorithm used to find **Strongly Connected Components (SCCs)** in a **directed graph**. It works by processing vertices in decreasing order of finishing time, reversing the graph, and performing a second DFS to extract each strongly connected component.

---

## 📚 Problems Covered

- 🔄 Strongly Connected Components (SCC)

---

## 🎯 Concepts Practiced

- Strongly Connected Components (SCC)
- Depth First Search (DFS)
- Graph Transposition (Reverse Graph)
- Topological Finishing Order
- Stack Ordering
- Component Extraction

---

## 💡 What You'll Learn

- What Strongly Connected Components are
- Why SCCs only exist in directed graphs
- Understanding DFS finishing order
- Why reversing the graph works
- Extracting SCCs efficiently
- Time and Space Complexity analysis

---

## ⚙️ Algorithm Overview

1. Perform a DFS on the original graph.
2. Push every vertex into a stack after finishing its DFS.
3. Reverse all graph edges.
4. Pop vertices from the stack one by one.
5. Perform DFS on the reversed graph.
6. Each DFS traversal gives one Strongly Connected Component.

---

## 🚀 Why Kosaraju Works

The first DFS computes the correct processing order based on finishing times.

After reversing the graph, processing vertices in this order ensures that each DFS remains inside exactly one Strongly Connected Component before moving to the next.

---

## 🌍 Real World Applications

- 🌐 Website Link Analysis
- 📱 Social Network Communities
- 🔄 Compiler Dependency Analysis
- 📡 Communication Networks
- 📦 Package Dependency Resolution
- 🛣️ Route Optimization

---

## 🧠 Time Complexity

| Operation | Complexity |
|-----------|------------|
| First DFS | **O(V + E)** |
| Reverse Graph | **O(V + E)** |
| Second DFS | **O(V + E)** |
| Overall | **O(V + E)** |

---

## 📌 Key Idea

```
Original Graph

      DFS
       │
       ▼
 Finishing Order

       │
       ▼
 Reverse Graph

       │
       ▼
 DFS in Reverse Order

       │
       ▼
 Strongly Connected Components
```

---

> **"Reverse the graph, respect the finishing order, and every hidden strongly connected component reveals itself."** 🔄
