/*
-------------------------------------
🧩 Problem: Remove Nth Node From End
📂 Category: Linked List / Fast-Slow Pointers
🧠 Concept: Fixed-gap pointer traversal

⚡ Approach:
- Create dummy node
- Move fast pointer n steps ahead
- Move both pointers together
- Slow pointer reaches node
  before deletion target

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Maintain a fixed distance between pointers

-------------------------------------
*/

class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head,
                               int n) {

        ListNode* dummyNode =
            new ListNode(0);

        dummyNode->next = head;

        ListNode* fastPointer = dummyNode;
        ListNode* slowPointer = dummyNode;

        // Create n-node gap
        for(int i = 0; i < n; i++) {

            fastPointer =
                fastPointer->next;
        }

        // Move together
        while(fastPointer->next) {

            fastPointer =
                fastPointer->next;

            slowPointer =
                slowPointer->next;
        }

        // Delete target node
        ListNode* nodeToDelete =
            slowPointer->next;

        slowPointer->next =
            slowPointer->next->next;

        delete nodeToDelete;

        return dummyNode->next;
    }
};
