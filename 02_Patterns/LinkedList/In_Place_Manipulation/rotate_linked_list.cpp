/*
-------------------------------------
🧩 Problem: Rotate Linked List
📂 Category: Linked List / Rearrangement
🧠 Concept: Circular list manipulation

⚡ Approach:
- Find list length and tail
- Convert list into circular list
- Find new tail after rotation
- Break circular connection

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Rotation becomes easy after forming a cycle

-------------------------------------
*/

class Solution {
public:

    Node* rotate(Node* head, int k) {

        if(!head || k == 0) {
            return head;
        }

        // Find length and tail
        int length = 1;

        Node* tail = head;

        while(tail->next) {

            tail = tail->next;

            length++;
        }

        k %= length;

        if(k == 0) {
            return head;
        }

        // Form circular list
        tail->next = head;

        // Find new tail
        Node* newTail = head;

        for(int i = 1; i < k; i++) {

            newTail = newTail->next;
        }

        // New head
        Node* newHead = newTail->next;

        // Break cycle
        newTail->next = NULL;

        return newHead;
    }
};
