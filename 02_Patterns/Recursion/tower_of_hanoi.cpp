/*
-------------------------------------
🧩 Problem: Tower of Hanoi
📂 Category: Recursion (Pattern)
🧠 Concept: Divide and Conquer

⚡ Approach:
- Move n-1 disks from source → auxiliary
- Move nth disk from source → destination
- Move n-1 disks from auxiliary → destination

⏱️ Time Complexity: O(2^n)
💾 Space Complexity: O(n) (recursion stack)

🎯 Key Idea:
- Break problem into smaller subproblems

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        int moves = 0;
        solve(n, from, to, aux, moves);
        return moves;
    }

private:
    void solve(int n, int from, int to, int aux, int &moves) {
        if(n == 0) return;

        // Step 1: Move n-1 disks to auxiliary
        solve(n - 1, from, aux, to, moves);

        // Step 2: Move nth disk
        cout << "Move disk " << n << " from rod " << from 
             << " to rod " << to << endl;
        moves++;

        // Step 3: Move n-1 disks to destination
        solve(n - 1, aux, to, from, moves);
    }
};
