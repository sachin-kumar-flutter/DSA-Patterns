/*
-------------------------------------
🧩 Problem: Hollow Rectangle Pattern
📂 Category: Basics (Pattern Printing)
🧠 Concept: Nested Loops + Boundary Conditions

⚡ Approach:
- Print '*' on borders:
    → First row, last row
    → First column, last column
- Else print space

⏱️ Time Complexity: O(n * m)
💾 Space Complexity: O(1)

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printHollowRect(int n, int m) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(i == 1 || i == n || j == 1 || j == m)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};
