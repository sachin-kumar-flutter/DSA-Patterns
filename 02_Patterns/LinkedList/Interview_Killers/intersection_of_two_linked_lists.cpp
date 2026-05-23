/*
-------------------------------------
🧩 Problem: Intersection of Two Linked Lists
📂 Category: Linked List / Two Pointers
🧠 Concept: Pointer synchronization

⚡ Approach:
- Traverse both lists simultaneously
- When pointer reaches end:
    redirect it to other list
- Pointers eventually align at
  intersection node

⏱️ Time Complexity: O(n + m)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Equalize traversal distance automatically

-------------------------------------
*/

class Solution {
public:

    Node* intersectPoint(Node* head1,
                         Node* head2) {

        Node* pointer1 = head1;
        Node* pointer2 = head2;

        while(pointer1 != pointer2) {

            pointer1 =
                pointer1
                ? pointer1->next
                : head2;

            pointer2 =
                pointer2
                ? pointer2->next
                : head1;
        }

        return pointer1;
    }
};
