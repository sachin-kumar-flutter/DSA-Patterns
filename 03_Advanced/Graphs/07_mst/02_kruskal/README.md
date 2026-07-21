# 🌲 Kruskal's Algorithm (Minimum Spanning Tree)

> Build the Minimum Spanning Tree by always choosing the **cheapest available edge** that doesn't create a cycle.

Kruskal's Algorithm is a greedy algorithm used to construct a **Minimum Spanning Tree (MST)**. Instead of growing from a starting vertex, it processes **all edges in increasing order of weight**, adding an edge only if it connects two different components. Union-Find (DSU) is used to efficiently detect cycles.

---

## 📚 Problems Covered

- 🌲 Minimum Spanning Tree (Kruskal's Algorithm)

---

## 🎯 Concepts Practiced

- Minimum Spanning Tree (MST)
- Greedy Algorithm
- Edge Sorting
- Union-Find (Disjoint Set Union)
- Path Compression
- Union by Rank / Size
- Cycle Detection

---

## 💡 What You'll Learn

- What a Minimum Spanning Tree is
- Why sorting edges guarantees the optimal answer
- Detecting cycles efficiently using DSU
- Difference between Prim's and Kruskal's algorithms
- Applying Union-Find in graph problems
- Time and Space Complexity analysis

---

## ⚙️ Algorithm Overview

1. Sort all edges in increasing order of weight.
2. Initialize every vertex as its own component.
3. Process edges one by one.
4. If an edge connects two different components, include it in the MST.
5. Merge the two components using Union-Find.
6. Ignore edges that would create a cycle.
7. Stop after selecting **V − 1** edges.

---

## 🚀 Why Kruskal's Works

By always choosing the smallest available edge that connects two different components, Kruskal never creates unnecessary cycles.

According to the **Cut Property**, the minimum-weight edge crossing any cut is always safe to include in the Minimum Spanning Tree.

---

## 🌍 Real World Applications

- 🌐 Network Cable Installation
- 🛣️ Road Construction
- ⚡ Electrical Grid Design
- 🚰 Water Distribution Networks
- 📡 Communication Networks
- 🏗️ Infrastructure Planning

---

## ⚖️ Prim's vs Kruskal's

| Feature | Prim's | Kruskal's |
|---------|---------|-----------|
| Starts From | Any Vertex | Smallest Edge |
| Grows | One Tree | Multiple Components |
| Uses | Priority Queue | Union-Find (DSU) |
| Cycle Detection | Visited Array | DSU |
| Time Complexity | O(E log V) | O(E log E) |

---

## 🧠 Time Complexity

| Step | Complexity |
|------|------------|
| Sort Edges | **O(E log E)** |
| Union-Find Operations | **O(E · α(V))** |
| Overall | **O(E log E)** |

---

> **"Kruskal's doesn't grow a tree—it keeps connecting forests until only one remains."** 🌲
