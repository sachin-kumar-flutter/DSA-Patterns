#include <bits/stdc++.h>
using namespace std;

/*
Topic: Stack Implementation
Operations: push, pop, top, isEmpty
*/

// =======================
// 1. Stack using Array
// =======================

class StackArray {
    int *arr;
    int topIndex;
    int capacity;

public:
    StackArray(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

// =======================
// 2. Stack using Linked List
// =======================

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class StackLL {
    Node* topNode;

public:
    StackLL() {
        topNode = NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (topNode == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == NULL;
    }
};

// =======================
// 3. Stack using STL
// =======================

void stackUsingSTL() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    st.pop();

    cout << "Top after pop: " << st.top() << endl;
}

// =======================
// MAIN
// =======================

int main() {

    // Array Stack
    StackArray s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "Array Stack Top: " << s1.top() << endl;

    // Linked List Stack
    StackLL s2;
    s2.push(5);
    s2.push(10);
    cout << "LL Stack Top: " << s2.top() << endl;

    // STL Stack
    stackUsingSTL();

    return 0;
}
