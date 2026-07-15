class Solution {
    int timer = 0;

    void dfs(int node, int parent,
             vector<vector<int>>& graph,
             vector<int>& disc, vector<int>& low,
             vector<bool>& isAP) {

        disc[node] = low[node] = timer++;

        int children = 0;
        //  ↑ count DFS tree children of this node
        //  (NOT all neighbours, only unvisited ones we recurse into)

        for (int neighbour : graph[node]) {

            if (neighbour == parent) continue;

            if (disc[neighbour] == -1) {
                // TREE EDGE
                children++;
                dfs(neighbour, node, graph, disc, low, isAP);

                low[node] = min(low[node], low[neighbour]);
                //  ↑ pull up reachability from child

                // AP CONDITION for non-root:
                // child cannot reach above current node
                // removing current node disconnects child's subtree
                if (parent != -1 && low[neighbour] >= disc[node])
                    isAP[node] = true;
                //  ↑ note >= not > (unlike bridges)
                //  >= means child reaches AT MOST node itself
                //  since node is removed, child is cut off

            }
            else {
                // BACK EDGE
                low[node] = min(low[node], disc[neighbour]);
            }
        }

        // AP CONDITION for root:
        // root is AP only if it has 2+ DFS tree children
        // (those subtrees only connect through root)
        if (parent == -1 && children > 1)
            isAP[node] = true;
    }

public:
    vector<int> findAPs(int n, vector<vector<int>>& graph) {
        vector<int> disc(n, -1), low(n, -1);
        vector<bool> isAP(n, false);

        for (int i = 0; i < n; i++)
            if (disc[i] == -1)
                dfs(i, -1, graph, disc, low, isAP);

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (isAP[i]) result.push_back(i);

        return result;
    }
};
