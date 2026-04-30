#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Implementation

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Insert at head
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);

    if(head != NULL) {
        head->prev = newNode;
        newNode->next = head;
    }

    return newNode;
}

// Insert at tail
Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);

    if(head == NULL) return newNode;

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Delete a node by value
Node* deleteNode(Node* head, int key) {
    if(head == NULL) return NULL;

    Node* temp = head;

    // If head needs to be deleted
    if(temp->data == key) {
        head = temp->next;
        if(head != NULL) head->prev = NULL;
        delete temp;
        return head;
    }

    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if(temp == NULL) return head;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
    return head;
}

// Traverse forward
void printForward(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    head = insertAtTail(head, 3);

    printForward(head);

    head = deleteNode(head, 2);
    printForward(head);

    return 0;
}
