/*
-------------------------------------
🧩 Problem: Majority Element (> n/3)
📂 Category: Arrays (Pattern - Boyer Moore Voting)
🧠 Concept: Extended Boyer-Moore Algorithm

⚡ Approach:
- At most 2 elements can appear more than n/3 times
- Maintain 2 candidates and their counts
- First pass: find potential candidates
- Second pass: verify their counts

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Cancel out different elements (voting mechanism)

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int candidate1 = 0, candidate2 = 1;
        int count1 = 0, count2 = 0;

        // Phase 1: Find candidates
        for(int num : arr) {
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
            else if(count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Phase 2: Verify candidates
        count1 = 0, count2 = 0;
        for(int num : arr) {
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
        }

        vector<int> ans;
        int n = arr.size();

        if(count1 > n/3) ans.push_back(candidate1);
        if(count2 > n/3) ans.push_back(candidate2);

        sort(ans.begin(), ans.end()); // cleaner than manual swap
        return ans;
    }
};
