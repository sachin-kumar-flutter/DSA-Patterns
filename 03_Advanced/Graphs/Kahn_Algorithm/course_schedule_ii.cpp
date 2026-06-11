/*
-------------------------------------
🧩 Problem: Course Schedule II
📂 Category: Graph / Topological Sort
🧠 Concept:
- Kahn's Algorithm
- BFS Topological Sort
- Indegree Tracking

⚡ Approach:
- Build prerequisite graph
- Compute indegree of each course
- Start with courses having
  indegree 0
- Process courses using BFS
- Add courses to topological order
- If all courses are processed,
  return the order

⏱️ Time Complexity: O(V + E)
💾 Space Complexity: O(V + E)

Where:
- V = Courses
- E = Prerequisites

🎯 Key Idea:
- Courses become available when
  all prerequisites are completed

-------------------------------------
*/

class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph:
        // prerequisite -> course
        for(auto& prerequisite : prerequisites) {

            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[prerequisiteCourse].push_back(course);
            indegree[course]++;
        }

        queue<int> bfsQueue;

        // Courses with no prerequisites
        for(int course = 0; course < numCourses; course++) if(indegree[course] == 0) bfsQueue.push(course);

        vector<int> courseOrder;

        while(!bfsQueue.empty()) {

            int currentCourse = bfsQueue.front();
            bfsQueue.pop();

            courseOrder.push_back(currentCourse);
            for(int nextCourse : graph[currentCourse]) if(--indegree[nextCourse] == 0) bfsQueue.push(nextCourses);
        }

        // Cycle exists if not all
        // courses are processed
        return courseOrder.size() == numCourses ? courseOrder : vector<int>{};
    }
};
