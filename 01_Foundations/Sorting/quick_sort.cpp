#include <bits/stdc++.h>
using namespace std;

/*
Quick Sort

Time Complexity:
- Best/Average: O(n log n)
- Worst: O(n^2)

Space: O(log n)
*/

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // choose last element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
}
