/*
-------------------------------------
🧩 Problem: Rotate Array by D Positions
📂 Category: Arrays (Pattern - Rotation)
🧠 Concept: Juggling Algorithm (GCD Based)

⚡ Approach:
- Divide array into sets using gcd(n, d)
- Rotate elements within each cycle

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;
        int g = gcd(n, d);

        for(int i = 0; i < g; i++) {
            int temp = arr[i];
            int j = i;

            while(true) {
                int k = j + d;
                if(k >= n) k -= n;
                if(k == i) break;

                arr[j] = arr[k];
                j = k;
            }

            arr[j] = temp;
        }
    }
};
