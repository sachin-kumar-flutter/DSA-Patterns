# 🌐 Floyd-Warshall Algorithm

> Compute the shortest distance between **every pair of vertices** using dynamic programming.

Floyd-Warshall is an elegant **All-Pairs Shortest Path (APSP)** algorithm that systematically improves the shortest distance between every pair of nodes by considering each vertex as an intermediate point. It works with **negative edge weights** (but not negative cycles) and is especially useful for dense graphs.

---

## 📚 Problems Covered

- 🏙️ Find the City With the Smallest Number of Neighbors at a Threshold Distance

---

## 🎯 Concepts Practiced

- All-Pairs Shortest Path (APSP)
- Dynamic Programming on Graphs
- Adjacency Matrix Representation
- Intermediate Vertex Optimization
- Negative Edge Handling
- Transitive Closure
- Reachability Analysis

---

## 💡 What You'll Learn

- Difference between Single Source and All-Pairs Shortest Path
- Why Floyd-Warshall uses Dynamic Programming
- Understanding the three nested loops
- Updating paths through intermediate vertices
- Detecting negative cycles
- Time and Space Complexity analysis

---

## ⚙️ Algorithm Overview

1. Build the adjacency matrix.
2. Initialize:
   - Distance to self = 0
   - Direct edge weight = edge cost
   - No edge = ∞
3. Pick every vertex one by one as an intermediate node.
4. Update every pair of vertices if passing through the intermediate node produces a shorter path.
5. After processing all vertices, the matrix stores the shortest distance between every pair.

---

## 🚀 Why Floyd-Warshall Works

Instead of finding one shortest path at a time, Floyd-Warshall gradually allows more intermediate vertices to be used.

After processing the **k-th** vertex, every shortest path is guaranteed to use only vertices from **{1...k}** as intermediate nodes.

By the time every vertex has been processed, every possible path has been considered.

---

## 🌍 Real World Applications

- 🗺️ Road Network Analysis
- ✈️ Airline Route Planning
- 🌐 Computer Network Routing
- 🤖 Robotics Navigation
- 📊 Social Network Distance Analysis
- 🛰️ Communication Networks

---

## ⚖️ Dijkstra vs Bellman-Ford vs Floyd-Warshall

| Feature | Dijkstra | Bellman-Ford | Floyd-Warshall |
|---------|----------|--------------|----------------|
| Shortest Path Type | Single Source | Single Source | All Pairs |
| Negative Edges | ❌ No | ✅ Yes | ✅ Yes |
| Negative Cycle Detection | ❌ No | ✅ Yes | ✅ Yes |
| Time Complexity | O((V+E) log V) | O(V × E) | O(V³) |
| Technique | Greedy | Edge Relaxation | Dynamic Programming |

---

> **"Sometimes the best path between two cities is discovered only after exploring every possible middle city."** 🌐
