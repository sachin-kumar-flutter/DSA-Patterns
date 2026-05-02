/*
-------------------------------------
🧩 Problem: Hollow Diamond Pattern
📂 Category: Basics (Pattern Printing)
🧠 Concept: Symmetry + Hollow Structure

⚡ Approach:
- Total rows = 2*n - 1
- First half → decreasing spaces
- Second half → increasing spaces
- Print stars only at boundaries

⏱️ Time Complexity: O(n^2)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Use symmetry around the middle row
- Print stars only at edges to make it hollow

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++) {

        int spaces;
        if (i < n)
            spaces = n - i - 1;
        else
            spaces = i - n + 1;

        int stars = 2 * (n - spaces) - 1;

        // Leading spaces
        for (int j = 0; j < spaces; j++) cout << " ";

        // Hollow stars
        for (int k = 0; k < stars; k++) {
            if (k == 0 || k == stars - 1)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}
