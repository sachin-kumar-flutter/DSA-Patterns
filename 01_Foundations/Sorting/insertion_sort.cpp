#include <bits/stdc++.h>
using namespace std;

/*
Insertion Sort
- Build the sorted array one element at a time
- Insert each element into its correct position

Time Complexity:
- Best: O(n) (already sorted)
- Average/Worst: O(n^2)

Space: O(1)
*/

void insertionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at correct position
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    insertionSort(arr);

    for (int x : arr) cout << x << " ";
}
