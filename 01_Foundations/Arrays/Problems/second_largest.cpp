/*
-------------------------------------
🧩 Problem: Second Largest Element in Array
📂 Category: Arrays (Foundation)
🧠 Concept: Traversal + Tracking Max/Second Max

⚡ Approach:
- Maintain two variables: max (a) and second max (b)
- Traverse the array once
- Update max and second max accordingly
- Ensure second max is strictly less than max

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

⚠️ Edge Case:
- If all elements are same OR no second largest exists → return -1

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int a = INT_MIN, b = INT_MIN;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > a) {
                b = a;
                a = arr[i];
            }
            else if(arr[i] > b && arr[i] != a) {
                b = arr[i];
            }
        }

        // If second largest doesn't exist
        return (b == INT_MIN) ? -1 : b;
    }
};
