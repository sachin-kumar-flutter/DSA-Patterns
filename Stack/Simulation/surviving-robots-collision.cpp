#include <bits/stdc++.h>
using namespace std;

/*
Problem: Surviving Robots After Collisions

Approach:
1. Combine all robot data into a single structure:
   {position, health, direction, original_index}

2. Sort robots by position to simulate real collision order.

3. Use a stack to keep track of robots moving to the right ('R').

4. For each robot:
   - If moving right → push to stack.
   - If moving left → resolve collisions with stack robots.

5. Collision Rules:
   - Lower health robot dies.
   - Higher health robot loses 1 health.
   - If equal → both die.

6. Store surviving robots' health using original indices.

7. Return survivors in original input order.
*/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // Step 1: Combine all data
        // robots[i] = {position, health, direction(char), original_index}
        vector<vector<int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        // Step 2: Sort robots by position
        sort(robots.begin(), robots.end());

        // Stack to store indices of robots moving right
        stack<int> st;

        for(int i = 0; i < n; i++) {

            // If robot is moving right, push to stack
            if(robots[i][2] == 'R') {
                st.push(i);
            }
            else {
                // Robot moving left → possible collisions
                while(!st.empty() && robots[st.top()][2] == 'R') {

                    int j = st.top(); // index of right-moving robot

                    // Case 1: Current robot stronger
                    if(robots[i][1] > robots[j][1]) {
                        robots[i][1]--;     // current loses 1 health
                        robots[j][1] = 0;   // stack robot dies
                        st.pop();           // remove dead robot
                    }
                    // Case 2: Stack robot stronger
                    else if(robots[i][1] < robots[j][1]) {
                        robots[j][1]--;     // stack robot loses 1 health
                        robots[i][1] = 0;   // current robot dies
                        break;
                    }
                    // Case 3: Equal health → both die
                    else {
                        robots[j][1] = 0;
                        robots[i][1] = 0;
                        st.pop();
                        break;
                    }
                }

                // If current robot survives, push to stack
                if(robots[i][1] > 0) {
                    st.push(i);
                }
            }
        }

        // Step 3: Store results in original order
        vector<int> result(n, -1);

        for(int i = 0; i < n; i++) {
            if(robots[i][1] > 0) {
                int original_index = robots[i][3];
                result[original_index] = robots[i][1];
            }
        }

        // Step 4: Collect surviving robots
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(result[i] != -1) {
                ans.push_back(result[i]);
            }
        }

        return ans;
    }
};
