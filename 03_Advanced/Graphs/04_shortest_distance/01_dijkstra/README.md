# ⚡ Dijkstra's Algorithm

> Find the shortest path, optimize routes, and master one of the most powerful graph algorithms used in real-world navigation systems.

Dijkstra's Algorithm computes the **minimum distance from a source node to every other reachable node** in a graph with **non-negative edge weights**. It is the foundation behind GPS navigation, network routing, flight planning, game AI, and countless shortest-path problems.

---

## 📚 Problems Covered

- 🌐 Network Delay Time
- 🏔️ Path With Minimum Effort

---

## 🎯 Concepts Practiced

- Single Source Shortest Path (SSSP)
- Greedy Strategy
- Min Heap (Priority Queue)
- Relaxation Technique
- Distance Array
- Weighted Graph Traversal
- Matrix as a Graph
- Modified Dijkstra Variants

---

## 💡 What You'll Learn

- Why BFS fails on weighted graphs
- How Dijkstra always expands the closest unexplored node
- Understanding the relaxation process
- Using Min Heap to optimize performance
- Solving shortest path problems on both graphs and grids
- Recognizing when Dijkstra can be modified for custom optimization problems
- Time and Space Complexity analysis

---

## ⚙️ Algorithm Overview

1. Initialize every node's distance as **∞** except the source (0).
2. Push the source into a **Min Heap**.
3. Always process the node with the **smallest current distance**.
4. Relax all its neighboring edges.
5. If a shorter path is found, update the distance and push it back into the heap.
6. Continue until the heap becomes empty.

---

## 🚀 Why Dijkstra Works

At every step, Dijkstra chooses the **nearest unprocessed node**.

Since all edge weights are **non-negative**, no future path can make this node's distance smaller. Once a node leaves the priority queue with its minimum distance, that distance is permanently finalized.

This greedy property is what makes Dijkstra both **correct** and **efficient**.

---

## 🌍 Real World Applications

- 🗺️ GPS Navigation
- 🌐 Internet Routing Protocols
- ✈️ Flight Route Optimization
- 🚚 Delivery & Logistics Planning
- 🎮 Game AI Pathfinding
- 🤖 Robotics Navigation

---

## 🚫 When NOT to Use Dijkstra

Dijkstra **does not work correctly** when the graph contains **negative edge weights**.

For such graphs, algorithms like **Bellman-Ford** or **Floyd-Warshall** are required.

---

> **"The shortest journey isn't found by exploring everything—it's found by always taking the safest next step."** ⚡
