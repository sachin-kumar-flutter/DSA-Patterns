/*
-------------------------------------
🧩 Problem: Allocate Minimum Number of Pages
📂 Category: Binary Search (Binary Search on Answer)
🧠 Concept: Minimize maximum pages assigned

⚡ Approach:
- Search answer in range:
    [max(arr), sum(arr)]
- Check if books can be allocated
  within given maximum pages
- Minimize the feasible answer

⏱️ Time Complexity: O(n log(sum))
💾 Space Complexity: O(1)

🎯 Key Idea:
- Binary search on maximum allowed pages

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findPages(vector<int> &arr, int k) {

        int n = arr.size();

        if(n < k) return -1;

        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);

        int ans = right;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(isPossible(arr, k, mid)) {
                ans = mid;
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(vector<int> &arr, int k, int pages) {

        int students = 1;
        int currentPages = 0;

        for(int x : arr) {

            if(currentPages + x <= pages) {
                currentPages += x;
            }

            else {
                students++;
                currentPages = x;
            }
        }

        return students <= k;
    }
};
