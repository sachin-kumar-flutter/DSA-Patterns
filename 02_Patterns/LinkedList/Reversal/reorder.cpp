/*
-------------------------------------
🧩 Problem: Reorder List
📂 Category: Linked List / Rearrangement
🧠 Concept:
- Find middle
- Reverse second half
- Merge alternately

⚡ Approach:
1. Find middle using fast-slow pointers
2. Reverse second half
3. Merge both halves alternately

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Combine multiple linked list patterns together

-------------------------------------
*/

class Solution {
public:

    void reorderList(ListNode* head) {

        if(!head || !head->next) {
            return;
        }

        // Find middle
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer->next &&
              fastPointer->next->next) {

            slowPointer = slowPointer->next;

            fastPointer = fastPointer->next->next;
        }

        // Reverse second half
        ListNode* previousNode = NULL;

        ListNode* currentNode = slowPointer->next;

        slowPointer->next = NULL;

        while(currentNode) {

            ListNode* nextNode = currentNode->next;

            currentNode->next = previousNode;

            previousNode = currentNode;

            currentNode = nextNode;
        }

        // Merge both halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = previousNode;

        while(secondHalf) {

            ListNode* firstNext = firstHalf->next;

            ListNode* secondNext = secondHalf->next;

            firstHalf->next = secondHalf;

            secondHalf->next = firstNext;

            firstHalf = firstNext;
            secondHalf = secondNext;
        }
    }
};
