/*
-------------------------------------
🧩 Problem: Find All Divisors of a Number
📂 Category: Maths (Number Theory)
🧠 Concept: Pair of Divisors (√n optimization)

⚡ Approach:
- Iterate i from 1 to √n
- If i divides n:
    → i is a divisor
    → n/i is also a divisor (pair)
- Avoid duplicate when i*i == n
- Sort the result at the end

⏱️ Time Complexity: O(√n + k log k) (k = number of divisors)
💾 Space Complexity: O(k)

🎯 Key Idea:
- Divisors come in pairs → check only up to √n

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getDivisors(int n) {
        vector<int> ans;

        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                ans.push_back(i);

                if(i != n / i) {
                    ans.push_back(n / i);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
