/*
-------------------------------------
🧩 Problem: Spiral Matrix IV (Fill Matrix from Linked List)
📂 Category: Matrix (Pattern - Spiral + Linked List)
🧠 Concept: Boundary Traversal + Simulation

⚡ Approach:
- Initialize matrix with -1
- Traverse in spiral order
- Fill values from linked list
- Stop when list ends

⏱️ Time Complexity: O(m * n)
💾 Space Complexity: O(m * n)

🎯 Key Idea:
- Combine spiral traversal with linked list iteration

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while(head && left <= right && top <= bottom) {

            // Top row
            for(int i = left; i <= right && head; i++) {
                ans[top][i] = head->val;
                head = head->next;
            }
            top++;

            // Right column
            for(int i = top; i <= bottom && head; i++) {
                ans[i][right] = head->val;
                head = head->next;
            }
            right--;

            // Bottom row
            if(top <= bottom) {
                for(int i = right; i >= left && head; i--) {
                    ans[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }

            // Left column
            if(left <= right) {
                for(int i = bottom; i >= top && head; i--) {
                    ans[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
        }

        return ans;
    }
};
