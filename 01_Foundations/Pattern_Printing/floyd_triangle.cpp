/*
-------------------------------------
🧩 Problem: Floyd’s Triangle
📂 Category: Basics (Pattern Printing)
🧠 Concept: Nested Loops + Incremental Pattern

⚡ Approach:
- Use a counter variable starting from 1
- Outer loop controls rows
- Inner loop prints increasing numbers
- Increment value after each print

⏱️ Time Complexity: O(n^2)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Understand how values evolve row by row

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << num++ << " ";
        }
        cout << endl;
    }

    return 0;
}
