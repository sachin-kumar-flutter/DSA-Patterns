/*
-------------------------------------
🧩 Problem: Prime Factorization
📂 Category: Maths (Number Theory)
🧠 Concept: Trial Division

⚡ Approach:
1. Remove all factors of 2
2. Check odd numbers from 3 to √n
3. If remaining n > 2 → it is prime

⏱️ Time Complexity: O(√n)
💾 Space Complexity: O(k) (number of factors)

🎯 Key Idea:
- Factors always come in pairs → only check up to √n

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;

    // Step 1: handle factor 2
    while(n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Step 2: check odd numbers
    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // Step 3: remaining prime
    if(n > 2) {
        factors.push_back(n);
    }

    return factors;
}
