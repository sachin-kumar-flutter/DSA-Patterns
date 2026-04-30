#include <bits/stdc++.h>
using namespace std;

/*
Topic: Queue Implementation
Operations: enqueue, dequeue, front, isEmpty
*/

// =======================
// 1. Queue using Array
// =======================

class QueueArray {
    int *arr;
    int frontIndex, rearIndex, capacity;

public:
    QueueArray(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
    }

    void enqueue(int x) {
        if (rearIndex == capacity - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rearIndex] = x;
    }

    void dequeue() {
        if (frontIndex > rearIndex) {
            cout << "Queue Underflow\n";
            return;
        }
        frontIndex++;
    }

    int front() {
        if (frontIndex > rearIndex) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() {
        return frontIndex > rearIndex;
    }
};

// =======================
// 2. Queue using Linked List
// =======================

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class QueueLL {
    Node *frontNode, *rearNode;

public:
    QueueLL() {
        frontNode = rearNode = NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rearNode == NULL) {
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    void dequeue() {
        if (frontNode == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == NULL)
            rearNode = NULL;

        delete temp;
    }

    int front() {
        if (frontNode == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return frontNode->data;
    }

    bool isEmpty() {
        return frontNode == NULL;
    }
};

// =======================
// 3. Queue using STL
// =======================

void queueUsingSTL() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;

    q.pop();

    cout << "Front after pop: " << q.front() << endl;
}

// =======================
// MAIN
// =======================

int main() {

    // Array Queue
    QueueArray q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout << "Array Queue Front: " << q1.front() << endl;

    // Linked List Queue
    QueueLL q2;
    q2.enqueue(5);
    q2.enqueue(10);
    cout << "LL Queue Front: " << q2.front() << endl;

    // STL Queue
    queueUsingSTL();

    return 0;
}
