# 🌐 Graph Algorithms

> Master graph theory from traversal to advanced connectivity, shortest paths, spanning trees, and strongly connected components.

Graphs are one of the most important topics in Data Structures and Algorithms. They model relationships between objects and are widely used in navigation systems, social networks, dependency management, networking, and competitive programming.

This directory contains a carefully structured roadmap of graph algorithms—from beginner concepts like **BFS & DFS** to advanced algorithms such as **Tarjan's** and **Kosaraju's**.

---

# 📂 Learning Roadmap

## 01. 🌊 BFS & DFS Basics

Learn how to traverse graphs and grids efficiently.

**Topics Covered**

- Breadth First Search (BFS)
- Depth First Search (DFS)
- Grid Traversal
- Connected Components
- Multi-Source BFS
- Flood Fill

---

## 02. 🔄 Cycle Detection

Understand how to determine whether a graph contains cycles.

**Topics Covered**

- Directed Graph Cycle Detection
- DFS Recursion Stack
- Kahn's Algorithm
- Safe States

---

## 03. 📋 Topological Sort

Solve dependency ordering problems using Directed Acyclic Graphs (DAGs).

**Topics Covered**

- Kahn's Algorithm
- DFS Topological Sort
- In-Degree
- Dependency Resolution

---

## 04. 🛣️ Shortest Path Algorithms

Find the minimum cost path in weighted graphs.

### ⚡ Dijkstra
- Non-negative edge weights
- Greedy + Priority Queue

### 🔥 Bellman-Ford
- Negative edge weights
- Negative cycle detection

### 🌐 Floyd-Warshall
- All-Pairs Shortest Path
- Dynamic Programming

---

## 05. 🎭 Bipartite Graph Check

Determine whether a graph can be divided into two independent groups.

**Topics Covered**

- Graph Coloring
- BFS Coloring
- DFS Coloring
- Odd Cycle Detection

---

## 06. 🔗 Union-Find (DSU)

Efficiently manage dynamic connectivity.

**Topics Covered**

- Disjoint Set Union
- Path Compression
- Union by Rank
- Union by Size
- Connected Components

---

## 07. 🌳 Minimum Spanning Tree (MST)

Connect every vertex with the minimum total edge weight.

### 🌱 Prim's Algorithm
- Greedy
- Priority Queue

### 🌲 Kruskal's Algorithm
- Edge Sorting
- Union-Find

---

## 08. 🔍 Tarjan's Algorithm

Identify the critical parts of a graph.

**Topics Covered**

- Articulation Points
- Bridges
- Discovery Time
- Low-Link Values

---

## 09. 🔄 Kosaraju's Algorithm

Find Strongly Connected Components in directed graphs.

**Topics Covered**

- Strongly Connected Components
- Graph Transposition
- Finishing Time
- Reverse DFS

---

# 🧠 Skills You'll Master

By completing this section, you'll be able to:

- ✅ Represent graphs using adjacency lists and matrices
- ✅ Traverse graphs using BFS and DFS
- ✅ Detect cycles in directed and undirected graphs
- ✅ Solve scheduling and dependency problems
- ✅ Find shortest paths in weighted graphs
- ✅ Build Minimum Spanning Trees
- ✅ Detect bridges and articulation points
- ✅ Work with Strongly Connected Components
- ✅ Solve advanced graph interview problems confidently

---

# ⚖️ Algorithm Selection Guide

```text
Need to traverse a graph?
        │
        ▼
     BFS / DFS

Need to detect a cycle?
        │
        ▼
Cycle Detection

Need task ordering?
        │
        ▼
Topological Sort

Need shortest path?
        │
        ▼
 ┌───────────────┬──────────────────────┐
 │               │                      │
 ▼               ▼                      ▼
Dijkstra    Bellman-Ford        Floyd-Warshall
(No -ve)    (Negative Edges)     (All Pairs)

Need to divide into two groups?
        │
        ▼
 Bipartite Check

Need dynamic connectivity?
        │
        ▼
 Union-Find (DSU)

Need minimum cost network?
        │
        ▼
Minimum Spanning Tree
 ┌───────────────┐
 ▼               ▼
Prim         Kruskal

Need critical nodes or edges?
        │
        ▼
 Tarjan

Need Strongly Connected Components?
        │
        ▼
 Kosaraju
```

---

# 🌍 Real World Applications

- 🗺️ GPS Navigation
- 🌐 Internet Routing
- 📱 Social Networks
- 🏗️ Infrastructure Planning
- ⚡ Electrical Networks
- 📦 Package Dependency Resolution
- 🚚 Logistics & Transportation
- 🤖 Robotics & Game AI
- 💹 Financial Network Analysis

---

# 🚀 Learning Journey

```
Graph Representation
        │
        ▼
   BFS & DFS
        │
        ▼
Cycle Detection
        │
        ▼
Topological Sort
        │
        ▼
Shortest Paths
        │
        ▼
Bipartite Graphs
        │
        ▼
Union-Find (DSU)
        │
        ▼
Minimum Spanning Tree
        │
        ▼
Tarjan
        │
        ▼
Kosaraju
```

---

> **"Graphs aren't just nodes and edges—they're a way of modeling relationships. Master them, and you'll unlock solutions to some of the most powerful problems in computer science."** 🌐
