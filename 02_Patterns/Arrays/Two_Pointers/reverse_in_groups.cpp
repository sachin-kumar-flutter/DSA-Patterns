/*
-------------------------------------
🧩 Problem: Reverse Array in Groups of K
📂 Category: Arrays (Pattern - Two Pointers)
🧠 Concept: Chunk Processing + In-place Reversal

⚡ Approach:
- Traverse array in steps of k
- For each segment:
    → Reverse elements from i to min(i+k-1, n-1)
- Use two pointers (start, end) for reversal

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Break array into chunks and reverse each independently

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseInGroups(vector<int> &arr, int k) {
        int n = arr.size();

        for(int i = 0; i < n; i += k) {
            int start = i;
            int end = min(i + k - 1, n - 1);

            while(start < end) {
                swap(arr[start++], arr[end--]);
            }
        }
    }
};
