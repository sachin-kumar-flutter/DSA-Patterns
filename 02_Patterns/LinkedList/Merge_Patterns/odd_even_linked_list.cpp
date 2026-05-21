/*
-------------------------------------
🧩 Problem: Odd Even Linked List
📂 Category: Linked List / Rearrangement
🧠 Concept: Pointer-based partitioning

⚡ Approach:
- Maintain separate odd/even chains
- Traverse list while rearranging links
- Attach even list after odd list

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Rewire links without extra nodes

-------------------------------------
*/

class Solution {
public:

    ListNode* oddEvenList(ListNode* head) {

        if(!head) {
            return NULL;
        }

        ListNode* oddPointer = head;
        ListNode* evenPointer = head->next;

        ListNode* evenHead = evenPointer;

        while(evenPointer &&
              evenPointer->next) {

            // Connect odd nodes
            oddPointer->next =
                oddPointer->next->next;

            oddPointer =
                oddPointer->next;

            // Connect even nodes
            evenPointer->next =
                evenPointer->next->next;

            evenPointer =
                evenPointer->next;
        }

        // Attach even list after odd list
        oddPointer->next = evenHead;

        return head;
    }
};
