#include <bits/stdc++.h>
using namespace std;

/*
Heapify (Build Max Heap from Array)
*/

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build Heap in O(n)
void buildHeap(vector<int> &arr) {
    int n = arr.size();

    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    vector<int> arr = {3, 5, 1, 10, 2};

    buildHeap(arr);

    cout << "Max Heap: ";
    for (int x : arr)
        cout << x << " ";
}
