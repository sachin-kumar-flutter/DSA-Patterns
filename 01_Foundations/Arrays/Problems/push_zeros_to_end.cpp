/*
-------------------------------------
🧩 Problem: Push Zeros to End
📂 Category: Arrays (Foundation)
🧠 Concept: Two Pointer Technique (In-place)

⚡ Approach:
- Maintain a pointer 'count' to track position of next non-zero element
- Traverse the array:
    → If current element is non-zero, swap it with arr[count]
    → Increment count
- This ensures all non-zero elements come forward, and zeros shift to the end

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Stable partitioning of array (relative order maintained)

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int count = 0; // Pointer for position of next non-zero element

        for(int i = 0; i < arr.size(); i++) {
            // If current element is non-zero
            if(arr[i] != 0) {
                // Swap it with element at 'count'
                swap(arr[i], arr[count]);
                count++; // Move count forward
            }
        }
    }
};
