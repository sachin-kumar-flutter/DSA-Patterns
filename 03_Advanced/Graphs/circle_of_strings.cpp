class Solution {
public:

    // DFS to mark all reachable vertices
    void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited, adj);
            }
        }
    }

    bool isCircle(vector<string> &arr) {

        // Graph of 26 lowercase English letters
        vector<vector<int>> graph(26);

        // Store indegree and outdegree of each character
        vector<int> indegree(26, 0);
        vector<int> outdegree(26, 0);

        // Build directed graph:
        // first character -> last character
        for (string s : arr) {
            int u = s[0] - 'a';
            int v = s[s.size() - 1] - 'a';

            outdegree[u]++;
            indegree[v]++;

            graph[u].push_back(v);
        }

        // For an Eulerian Circuit in a directed graph,
        // indegree and outdegree of every vertex must be equal.
        for (int i = 0; i < 26; i++) {
            if (indegree[i] != outdegree[i]) {
                return false;
            }
        }

        // Check connectivity of all characters
        // that participate in the graph.
        vector<bool> visited(26, false);

        // Start DFS from the first string's starting character
        dfs(arr[0][0] - 'a', visited, graph);

        // Every vertex having non-zero degree
        // should be reachable from the starting vertex.
        for (int i = 0; i < 26; i++) {
            if (indegree[i] > 0 && !visited[i]) {
                return false;
            }
        }

        return true;
    }
};
