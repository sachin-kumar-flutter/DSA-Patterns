# 🛣️ Shortest Path Algorithms

> Every shortest path problem looks similar—but choosing the right algorithm makes all the difference.

This directory contains the three most important shortest path algorithms in graph theory. Each algorithm is designed for a different type of graph and problem statement, ranging from finding the shortest route from a single source to computing the shortest distance between every pair of vertices.

---

## 📂 Algorithms Covered

### ⚡ Dijkstra's Algorithm
**Best for:** Graphs with **non-negative edge weights**

- Single Source Shortest Path (SSSP)
- Greedy Algorithm
- Priority Queue (Min Heap)
- Fast and efficient
- Time Complexity: **O((V + E) log V)**

📌 Use when:
- Edge weights are non-negative
- Fastest shortest path is required
- GPS, routing, navigation systems

---

### 🔥 Bellman-Ford Algorithm
**Best for:** Graphs containing **negative edge weights**

- Single Source Shortest Path (SSSP)
- Edge Relaxation
- Detects Negative Weight Cycles
- Works where Dijkstra fails
- Time Complexity: **O(V × E)**

📌 Use when:
- Negative edge weights exist
- Negative cycle detection is required
- Financial networks and arbitrage problems

---

### 🌐 Floyd-Warshall Algorithm
**Best for:** Finding shortest paths **between every pair of vertices**

- All-Pairs Shortest Path (APSP)
- Dynamic Programming
- Works with negative edges
- Detects Negative Cycles
- Time Complexity: **O(V³)**

📌 Use when:
- Distance between every pair of nodes is needed
- Dense graphs
- Network analysis and routing tables

---

## ⚖️ Algorithm Comparison

| Feature | ⚡ Dijkstra | 🔥 Bellman-Ford | 🌐 Floyd-Warshall |
|----------|------------|-----------------|------------------|
| Technique | Greedy | Edge Relaxation | Dynamic Programming |
| Shortest Path | Single Source | Single Source | All Pairs |
| Negative Edges | ❌ No | ✅ Yes | ✅ Yes |
| Negative Cycle Detection | ❌ No | ✅ Yes | ✅ Yes |
| Time Complexity | O((V+E) log V) | O(V × E) | O(V³) |
| Best For | Sparse Graphs | Negative Weights | Dense Graphs |

---

## 🧠 Which Algorithm Should You Choose?

```text
Need shortest path from ONE source?

        │
        ▼

Are there negative edge weights?

        │
   ┌────┴────┐
   │         │
  No        Yes
   │         │
   ▼         ▼
Dijkstra  Bellman-Ford


Need shortest paths between EVERY pair of vertices?

        │
        ▼

Floyd-Warshall
```

---

## 🎯 Learning Outcomes

By completing this section, you'll understand:

- The difference between Single Source and All-Pairs Shortest Path
- Greedy vs Dynamic Programming approaches
- Edge Relaxation and its significance
- When Dijkstra fails
- Why Bellman-Ford needs **V − 1** iterations
- How Floyd-Warshall computes every shortest path simultaneously
- Selecting the right algorithm based on graph constraints

---

## 🚀 Real World Applications

- 🗺️ GPS & Navigation Systems
- 🌐 Internet Routing Protocols
- ✈️ Flight Route Optimization
- 🚚 Logistics & Delivery Networks
- 💹 Currency Exchange Analysis
- 🤖 Robotics & Game AI
- 📡 Communication Networks

---

> **"Every shortest path problem has a solution—the real challenge is choosing the right algorithm to find it."** 🛣️
