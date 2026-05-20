/*
-------------------------------------
🧩 Problem: Reverse Linked List
📂 Category: Linked List / Foundation
🧠 Concept: Iterative pointer reversal

⚡ Approach:
- Maintain:
    prevNode
    currentNode
    nextNode
- Reverse links one by one

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Reverse pointer direction iteratively

-------------------------------------
*/

class Solution {
public:

    ListNode* reverseList(ListNode* head) {

        ListNode* previousNode = NULL;
        ListNode* currentNode = head;

        while(currentNode != NULL) {

            // Store next node
            ListNode* nextNode =
                currentNode->next;

            // Reverse link
            currentNode->next =
                previousNode;

            // Move pointers forward
            previousNode = currentNode;
            currentNode = nextNode;
        }

        return previousNode;
    }
};
