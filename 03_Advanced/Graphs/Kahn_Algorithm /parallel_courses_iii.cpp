/*
-------------------------------------
🧩 Problem: Parallel Courses III
📂 Category: Graph / Topological Sort
🧠 Concept:
- Kahn's Algorithm
- DAG Dynamic Programming

⚡ Approach:
- Perform topological sort
- dp[i] stores earliest time
  to complete course i
- Update neighbors using
  longest prerequisite path

⏱️ Time Complexity: O(V + E)
💾 Space Complexity: O(V + E)

🎯 Key Idea:
- A course can start only after
  all prerequisites finish
- Use DP on DAG to track the
  earliest completion time

-------------------------------------
*/


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1,0);
        vector<int> dp(n+1);

        for(auto &r:relations){
            graph[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0) {
                q.push(i);
                dp[i]=time[i-1];
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int neighbour:graph[node]){
                dp[neighbour]=max(dp[neighbour],dp[node]+time[neighbour-1]);
                if(--indegree[neighbour]==0) q.push(neighbour);
            }
        }

        return *max_element(dp.begin()+1,dp.end());
    }
};
