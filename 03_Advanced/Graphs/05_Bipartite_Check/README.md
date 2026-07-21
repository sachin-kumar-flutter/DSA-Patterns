# 🎭 Bipartite Graph Check

> Divide a graph into two independent groups such that **no two adjacent vertices belong to the same group.**

This directory focuses on **Bipartite Graphs**, a fundamental concept in graph theory. These problems revolve around determining whether a graph can be colored using **only two colors** without any adjacent vertices sharing the same color. Bipartite checking forms the basis of many matching, scheduling, and partitioning problems.

---

## 📚 Problems Covered

- 🎨 Is Graph Bipartite?
- 🤝 Possible Bipartition

---

## 🎯 Concepts Practiced

- Two-Coloring Technique
- BFS Graph Coloring
- DFS Graph Coloring
- Connected Components
- Graph Traversal
- Conflict Detection
- Odd Cycle Identification

---

## 💡 What You'll Learn

- What makes a graph bipartite
- How graph coloring solves bipartite problems
- Implementing bipartite check using both BFS and DFS
- Why odd-length cycles make a graph non-bipartite
- Handling disconnected graphs
- Time and Space Complexity analysis

---

## ⚙️ Algorithm Overview

1. Assign an arbitrary color to any unvisited node.
2. Traverse the graph using **BFS** or **DFS**.
3. Color every adjacent node with the opposite color.
4. If two adjacent nodes ever receive the same color, the graph is **not bipartite**.
5. Repeat for every disconnected component.

---

## 🚀 Why Bipartite Checking Works

A graph is bipartite **if and only if** it can be colored using exactly **two colors**.

During traversal, every edge must always connect vertices of opposite colors.

If this rule is ever violated, the graph contains an **odd-length cycle**, making bipartition impossible.

---

## 🌍 Real World Applications

- 👥 Team Formation
- 📅 Scheduling Problems
- 🤝 Matching Algorithms
- 💼 Job Assignment
- 💑 Stable Pairing Problems
- 🌐 Network Partitioning

---

## ⚖️ BFS vs DFS

| Feature | BFS | DFS |
|---------|-----|-----|
| Traversal | Level by Level | Depth First |
| Coloring | Queue | Recursion / Stack |
| Time Complexity | O(V + E) | O(V + E) |
| Space Complexity | O(V) | O(V) |

Both approaches produce the same result. Choose whichever traversal you're more comfortable with.

---

> **"If two neighboring nodes ever wear the same color, the graph has broken the rules."** 🎭
