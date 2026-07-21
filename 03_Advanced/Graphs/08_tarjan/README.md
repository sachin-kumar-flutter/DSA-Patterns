# 🔍 Tarjan's Algorithm

> Discover the critical vertices and edges that hold a graph together using one elegant DFS traversal.

Tarjan's Algorithm is a DFS-based graph algorithm used to identify **Articulation Points (Cut Vertices)** and **Bridges (Critical Connections)** in an undirected graph. It leverages **discovery time** and **low-link values** to determine whether removing a vertex or edge disconnects the graph.

---

## 📚 Problems Covered

- 🔴 Articulation Points
- 🌉 Bridges (Critical Connections)

---

## 🎯 Concepts Practiced

- Depth First Search (DFS)
- Discovery Time (`tin[]`)
- Low-Link Values (`low[]`)
- Back Edges
- Tree Edges
- Graph Connectivity
- Critical Nodes & Critical Edges

---

## 💡 What You'll Learn

- What Articulation Points and Bridges are
- Why DFS timestamps are powerful
- Understanding Discovery Time (`tin`)
- Understanding Low-Link Values (`low`)
- Difference between Tree Edges and Back Edges
- Detecting vulnerable parts of a network
- Time and Space Complexity analysis

---

## ⚙️ Algorithm Overview

1. Start a DFS traversal.
2. Assign every vertex a discovery timestamp (`tin`).
3. Maintain the lowest reachable discovery time (`low`) for every vertex.
4. Update `low[]` using back edges during DFS.
5. Use `tin[]` and `low[]` to identify:
   - **Articulation Points**
   - **Bridges**

---

## 🚀 Why Tarjan's Algorithm Works

During DFS, every node records:

- **When it was first discovered (`tin`)**
- **How far back it can reach (`low`)**

If a subtree cannot reach any ancestor of its parent, then the parent or connecting edge becomes critical for maintaining connectivity.

---

## 🌍 Real World Applications

- 🌐 Internet Network Reliability
- ⚡ Electrical Grid Analysis
- 🛣️ Road Network Vulnerability
- 📡 Communication Networks
- 🏙️ Infrastructure Planning
- 🔒 Network Failure Detection

---

## 🧠 Time Complexity

| Operation | Complexity |
|-----------|------------|
| DFS Traversal | **O(V + E)** |
| Space | **O(V)** |

---

## 📌 Key Conditions

### 🔴 Articulation Point

For a non-root vertex:

```text
low[child] >= tin[parent]
```

For the root:

```text
More than one DFS child
```

---

### 🌉 Bridge

```text
low[child] > tin[parent]
```

---

## ⚖️ Articulation Point vs Bridge

| Articulation Point | Bridge |
|--------------------|--------|
| Critical Vertex | Critical Edge |
| Removing it disconnects the graph | Removing it disconnects the graph |
| Uses `low >= tin` | Uses `low > tin` |

---

> **"Every graph has weak links—Tarjan's Algorithm finds them in a single DFS."** 🔍
