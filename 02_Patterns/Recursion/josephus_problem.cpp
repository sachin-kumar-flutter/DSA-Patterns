/*
-------------------------------------
🧩 Problem: Josephus Problem
📂 Category: Recursion / Math Pattern
🧠 Concept: Circular elimination

⚡ Problem:
- n people in a circle
- Every k-th person is eliminated
- Find the last remaining person

-------------------------------------
*/

/* -------------------------------
   🟢 Approach 1: Iterative (Preferred)
----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int josephus(int n, int k) {
        int ans = 0; // 0-based indexing

        for(int i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }

        return ans + 1; // convert to 1-based
    }
};


/* -------------------------------
   🔵 Approach 2: Recursive
----------------------------------*/

class SolutionRecursive {
public:
    int josephus(int n, int k) {
        if(n == 1) return 1;

        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
};
