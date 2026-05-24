/*
-------------------------------------
🧩 Problem: Sort Linked List
📂 Category: Advanced Linked List
🧠 Concept: Merge Sort on Linked List

⚡ Approach:
1. Find middle using fast-slow pointers
2. Split linked list into halves
3. Recursively sort both halves
4. Merge sorted lists

⏱️ Time Complexity: O(n log n)
💾 Space Complexity: O(log n)

🎯 Key Idea:
- Linked lists are naturally suited for merge sort

-------------------------------------
*/

class Solution {
public:

    ListNode* sortList(ListNode* head) {

        // Base case
        if(!head || !head->next) {
            return head;
        }

        // Find middle
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer->next && fastPointer->next->next) {

            slowPointer = slowPointer->next;

            fastPointer = fastPointer->next->next;
        }

        // Split list
        ListNode* secondHalf = slowPointer->next;

        slowPointer->next = NULL;

        // Sort both halves
        ListNode* leftHalf = sortList(head);

        ListNode* rightHalf = sortList(secondHalf);

        // Merge sorted halves
        return mergeLists(leftHalf, rightHalf);
    }

    ListNode* mergeLists(ListNode* leftList, ListNode* rightList) {

        ListNode* dummyNode = new ListNode(-1);

        ListNode* tailPointer = dummyNode;

        while(leftList && rightList) {

            if(leftList->val <= rightList->val) {

                tailPointer->next = leftList;

                leftList = leftList->next;
            }

            else {

                tailPointer->next = rightList;

                rightList = rightList->next;
            }

            tailPointer = tailPointer->next;
        }

        // Attach remaining nodes
        tailPointer->next = leftList ? leftList : rightList;

        return dummyNode->next;
    }
};
