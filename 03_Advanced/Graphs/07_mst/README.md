# 🌳 Minimum Spanning Tree (MST)

> Connect every vertex in a weighted graph with the **minimum possible total cost**, without forming any cycles.

A **Minimum Spanning Tree (MST)** is a subset of edges that connects **all vertices** in a graph while minimizing the total edge weight. MST algorithms are widely used in designing efficient and cost-effective networks such as roads, electrical grids, communication systems, and pipelines.

This directory covers the two most important greedy algorithms for constructing an MST: **Prim's Algorithm** and **Kruskal's Algorithm**.

---

## 📂 Algorithms Covered

### 🌳 Prim's Algorithm

**Idea:** Grow a single tree by repeatedly selecting the cheapest edge connecting the current tree to an unvisited vertex.

- Greedy Algorithm
- Priority Queue (Min Heap)
- Graph Traversal
- Best suited for dense graphs

**Time Complexity:** **O(E log V)**

---

### 🌲 Kruskal's Algorithm

**Idea:** Sort all edges and repeatedly choose the smallest edge that connects two different components.

- Greedy Algorithm
- Edge Sorting
- Union-Find (DSU)
- Best suited for sparse graphs

**Time Complexity:** **O(E log E)**

---

## 🎯 Concepts Practiced

- Minimum Spanning Tree (MST)
- Greedy Algorithms
- Cut Property
- Cycle Detection
- Priority Queue
- Union-Find (Disjoint Set Union)
- Graph Connectivity
- Edge Optimization

---

## 💡 What You'll Learn

- What a Minimum Spanning Tree is
- Difference between MST and Shortest Path
- Why greedy algorithms work for MST
- Prim's Algorithm intuition
- Kruskal's Algorithm intuition
- Choosing the right MST algorithm
- Time and Space Complexity analysis

---

## ⚖️ Prim's vs Kruskal's

| Feature | 🌳 Prim's | 🌲 Kruskal's |
|----------|----------|--------------|
| Starts From | Any Vertex | Smallest Edge |
| Builds | One Growing Tree | Multiple Components |
| Main Data Structure | Priority Queue | Union-Find (DSU) |
| Cycle Detection | Visited Array | DSU |
| Best For | Dense Graphs | Sparse Graphs |
| Time Complexity | O(E log V) | O(E log E) |

---

## 🧠 Prim or Kruskal?

```text
Need a Minimum Spanning Tree?

            │
            ▼

Is the graph dense?

      ┌─────┴─────┐
      │           │
    Yes          No
      │           │
      ▼           ▼
   Prim's     Kruskal's
```

---

## 🌍 Real World Applications

- ⚡ Electrical Grid Design
- 🌐 Internet & Communication Networks
- 🚰 Water Distribution Systems
- 🛣️ Road & Railway Construction
- 🏗️ Infrastructure Planning
- 🛰️ Satellite Network Design

---

## 🧠 MST vs Shortest Path

Many beginners confuse these two concepts.

| Minimum Spanning Tree | Shortest Path |
|------------------------|---------------|
| Connects **all** vertices | Finds the best path between vertices |
| Minimizes **total edge cost** | Minimizes **path cost** |
| One tree for the entire graph | Different path for each source |
| Uses Prim's / Kruskal's | Uses Dijkstra / Bellman-Ford / Floyd-Warshall |

---

## 🚀 The Big Idea

Both Prim's and Kruskal's solve the same problem—but from completely different perspectives.

- 🌳 **Prim's** starts with **one vertex** and grows **one tree**.
- 🌲 **Kruskal's** starts with **many tiny trees** and keeps merging them.

Different strategies, same optimal Minimum Spanning Tree.

---

> **"Shortest Path gets you to a destination cheaply. Minimum Spanning Tree connects the entire world cheaply."** 🌳
