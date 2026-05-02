/*
-------------------------------------
🧩 Problem: Pyramid Pattern
📂 Category: Basics (Pattern Printing)
🧠 Concept: Nested Loops + Alignment

⚡ Approach:
- For each row:
    → Print (n - i) spaces
    → Print (2*i - 1) stars
- This centers the pyramid

⏱️ Time Complexity: O(n^2)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Control spacing and symmetry using loops

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printPyramid(int n) {
        for(int i = 1; i <= n; i++) {

            // Print leading spaces
            for(int j = 1; j <= n - i; j++) {
                cout << " ";
            }

            // Print stars
            for(int j = 1; j <= 2 * i - 1; j++) {
                cout << "*";
            }

            cout << endl;
        }
    }
};
