#include <bits/stdc++.h>
using namespace std;

// Singly Linked List Implementation

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at head
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
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
    return head;
}

// Delete a node by value
Node* deleteNode(Node* head, int key) {
    if(head == NULL) return NULL;

    if(head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    while(temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if(temp->next != NULL) {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    return head;
}

// Traverse and print
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    head = insertAtHead(head, 3);
    head = insertAtHead(head, 1);
    head = insertAtTail(head, 5);

    printList(head);

    head = deleteNode(head, 3);
    printList(head);

    return 0;
}
