/*
-------------------------------------
🧩 Problem: Majority Element (> n/2)
📂 Category: Arrays (Pattern - Boyer Moore Voting)
🧠 Concept: Boyer-Moore Voting Algorithm

⚡ Approach:
- Maintain a single candidate and count
- If count becomes 0 → pick new candidate
- Increase/decrease count based on match

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Majority element always survives cancellation

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int candidate = 0, count = 0;

        for(int num : arr) {
            if(count == 0) {
                candidate = num;
            }

            if(num == candidate) count++;
            else count--;
        }

        return candidate; // guaranteed to exist
    }
};
