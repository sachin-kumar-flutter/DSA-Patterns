#include <bits/stdc++.h>
using namespace std;

/*
    Problem: H-Index

    Approach:
    ----------
    1. Sort the citations array in ascending order.
    2. Traverse the array from left to right.
    3. At index i:
        - Number of papers remaining = n - i
        - citations[i] is the minimum citation in this group

        So we check:
        -> Do we have (n - i) papers with at least (n - i) citations?

        If yes:
        -> citations[i] >= (n - i)
        -> This is a valid h-index

    4. Return the first such (n - i)
    5. If no valid value found, return 0

    Time Complexity: O(n log n) due to sorting
    Space Complexity: O(1)
*/

int hIndex(vector<int>& citations) {
    int n = citations.size();

    // Step 1: Sort citations in ascending order
    sort(citations.begin(), citations.end());

    // Step 2: Traverse and check condition
    for (int i = 0; i < n; i++) {
        int papers = n - i;  // number of papers from i to end

        // Check if current group satisfies h-index condition
        if (citations[i] >= papers) {
            return papers;
        }
    }

    // If no valid h-index found
    return 0;
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << "H-Index: " << hIndex(citations) << endl;
    return 0;
}
