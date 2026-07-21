# 🌳 Prim's Algorithm (Minimum Spanning Tree)

> Connect every vertex in a graph with the **minimum possible total edge weight**, without creating cycles.

Prim's Algorithm is a greedy algorithm used to construct a **Minimum Spanning Tree (MST)**. Starting from any vertex, it repeatedly selects the **minimum-weight edge** that connects a visited vertex to an unvisited vertex until all vertices become part of the tree.

---

## 📚 Problems Covered

- 🌳 Minimum Spanning Tree (Prim's Algorithm)

---

## 🎯 Concepts Practiced

- Minimum Spanning Tree (MST)
- Greedy Algorithm
- Priority Queue (Min Heap)
- Graph Traversal
- Visited Array
- Edge Selection
- Connected Weighted Graphs

---

## 💡 What You'll Learn

- What a Minimum Spanning Tree is
- Why Prim's algorithm is greedy
- Building an MST using a Min Heap
- Avoiding cycles naturally
- Difference between Prim's and Dijkstra's Algorithm
- Time and Space Complexity analysis

---

## ⚙️ Algorithm Overview

1. Start from any vertex.
2. Mark it as visited.
3. Push all outgoing edges into a Min Heap.
4. Pick the minimum-weight edge.
5. If it connects to an unvisited vertex, include it in the MST.
6. Repeat until all vertices are visited.

---

## 🚀 Why Prim's Works

At every step, Prim's chooses the **cheapest edge leaving the current tree**.

According to the **Cut Property**, the minimum-weight edge crossing any cut is always safe to include in the Minimum Spanning Tree.

Repeating this process eventually connects every vertex while guaranteeing the minimum total cost.

---

## 🌍 Real World Applications

- 🌐 Network Cable Installation
- ⚡ Electrical Grid Design
- 🛣️ Road Construction
- 🚰 Water Pipeline Networks
- 📡 Telecommunication Networks
- 🏗️ Infrastructure Planning

---

## ⚖️ Prim's vs Dijkstra

| Feature | Prim's | Dijkstra |
|---------|---------|----------|
| Goal | Minimum Spanning Tree | Shortest Path |
| Output | One MST | Shortest Distance from Source |
| Greedy Choice | Smallest Edge | Smallest Distance |
| Priority Queue Stores | Edge Weight | Distance |
| Path Matters | ❌ No | ✅ Yes |

---

## 🧠 Time Complexity

| Implementation | Complexity |
|---------------|------------|
| Priority Queue + Adjacency List | **O(E log V)** |
| Adjacency Matrix | **O(V²)** |

---

> **"Prim's doesn't care how far you've traveled—it only cares about the cheapest edge to grow the tree."** 🌳
