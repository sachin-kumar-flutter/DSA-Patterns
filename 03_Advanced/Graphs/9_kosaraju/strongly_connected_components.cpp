void dfs1(int node, vector<vector<int>>& graph,
          vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            dfs1(neighbor, graph, visited, st);
    }
    st.push(node);      // push after all neighbors done
}

void dfs2(int node, vector<vector<int>>& transposed,
          vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : transposed[node]) {
        if (!visited[neighbor])
            dfs2(neighbor, transposed, visited, component);
    }
}

vector<vector<int>> kosaraju(int n, vector<vector<int>>& graph) {
    // Step 1: DFS on original, fill stack by finish time
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs1(i, graph, visited, st);
    }

    // Step 2: Transpose graph
    vector<vector<int>> transposed(n);
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            transposed[v].push_back(u);     // reverse edge
        }
    }

    // Step 3: DFS on transposed in stack order
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    while (!st.empty()) {
        int node = st.top(); st.pop();

        if (!visited[node]) {
            vector<int> component;
            dfs2(node, transposed, visited, component);
            sccs.push_back(component);
        }
    }

    return sccs;    // each inner vector = one SCC
}
