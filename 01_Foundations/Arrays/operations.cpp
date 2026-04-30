// Topic: Arrays
// Operations: Traversal, Insertion, Deletion, Search
// Time Complexity:
// - Traversal: O(n)
// - Insertion: O(n)
// - Deletion: O(n)
// - Search: O(n)


#include <bits/stdc++.h>
using namespace std;

// Basic operations on arrays

// Traversal
void traverse(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insertion at index (shift required)
void insertAt(int arr[], int &n, int index, int value) {
    for(int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    n++;
}

// Deletion from index
void deleteAt(int arr[], int &n, int index) {
    for(int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Original array: ";
    traverse(arr, n);

    insertAt(arr, n, 2, 10);
    cout << "After insertion: ";
    traverse(arr, n);

    deleteAt(arr, n, 3);
    cout << "After deletion: ";
    traverse(arr, n);

    int index = linearSearch(arr, n, 10);
    cout << "Element found at index: " << index << endl;

    return 0;
}
