/*
-------------------------------------
🧩 Problem: Reverse an Array
📂 Category: Arrays (Foundation)
🧠 Concept: Two Pointer Technique

⚡ Approach:
- Use two pointers: one at start (i) and one at end (j)
- Swap elements at i and j
- Move i forward and j backward
- Continue until i < j

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- In-place reversal using symmetric swapping

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int> &arr) {
        int i = 0, j = arr.size() - 1;

        while(i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};
