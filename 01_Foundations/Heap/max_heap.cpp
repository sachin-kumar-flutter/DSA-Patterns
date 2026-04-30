#include <bits/stdc++.h>
using namespace std;

/*
Max Heap Implementation
Parent >= Children
*/

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap h;
    h.push(5);
    h.push(2);
    h.push(8);
    h.push(10);

    while (!h.isEmpty()) {
        cout << h.top() << " ";
        h.pop();
    }
}
