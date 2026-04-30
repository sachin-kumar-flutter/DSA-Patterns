#include <bits/stdc++.h>
using namespace std;

/*
Bubble Sort
- Repeatedly swap adjacent elements if they are in wrong order
- Largest element moves to the end in each pass

Time Complexity:
- Best: O(n) (if already sorted with optimization)
- Worst/Average: O(n^2)

Space: O(1)
*/

void bubbleSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Optimization: stop if already sorted
        if (!swapped) break;
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};

    bubbleSort(arr);

    for (int x : arr) cout << x << " ";
}
