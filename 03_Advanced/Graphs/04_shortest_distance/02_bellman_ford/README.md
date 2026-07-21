# 🔥 Bellman-Ford Algorithm

> Go beyond Dijkstra by solving shortest path problems even in the presence of **negative edge weights**.

Bellman-Ford is a powerful shortest path algorithm that computes the **minimum distance from a single source to all other vertices**. Unlike Dijkstra, it correctly handles graphs containing **negative edge weights** and can even detect **negative weight cycles**.

---

## 📚 Problems Covered

- ✈️ Cheapest Flights Within K Stops

---

## 🎯 Concepts Practiced

- Single Source Shortest Path (SSSP)
- Edge Relaxation
- Dynamic Programming Approach
- K-Edge Relaxation
- Negative Edge Handling
- Negative Cycle Detection
- Distance Array Optimization

---

## 💡 What You'll Learn

- Why Dijkstra fails with negative edges
- How repeated edge relaxation guarantees the shortest path
- Detecting negative weight cycles
- Limiting the number of edges (K Stops Variant)
- Difference between Dijkstra and Bellman-Ford
- Time and Space Complexity analysis

---

## ⚙️ Algorithm Overview

1. Initialize every node's distance as **∞**, except the source (0).
2. Relax every edge **V − 1** times.
3. During each iteration, update a node's distance if a shorter path is found.
4. Perform one extra iteration:
   - If any distance still decreases, a **negative weight cycle** exists.

---

## 🚀 Why Bellman-Ford Works

The shortest simple path between two vertices can contain **at most V − 1 edges**.

Each relaxation iteration guarantees the shortest paths using one additional edge.

After **V − 1** iterations, every shortest path has been discovered.

If another relaxation is still possible, the graph must contain a cycle whose total weight is negative.

---

## 🌍 Real World Applications

- ✈️ Flight Cost Optimization
- 🌐 Network Routing
- 💹 Currency Exchange & Arbitrage Detection
- 📡 Communication Networks
- 📊 Financial Graph Analysis

---

## ⚖️ Dijkstra vs Bellman-Ford

| Feature | Dijkstra | Bellman-Ford |
|---------|----------|--------------|
| Negative Edges | ❌ No | ✅ Yes |
| Negative Cycle Detection | ❌ No | ✅ Yes |
| Time Complexity | O((V+E) log V) | O(V × E) |
| Approach | Greedy | Edge Relaxation |

---

> **"Dijkstra trusts the nearest path. Bellman-Ford verifies every path."** 🔥
