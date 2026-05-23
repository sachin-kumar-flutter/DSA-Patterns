/*
-------------------------------------
🧩 Problem: Reverse Linked List II
📂 Category: Linked List / Reversal
🧠 Concept: Sublist reversal

⚡ Approach:
- Use dummy node for edge handling
- Reach node before reversal section
- Repeatedly move next node
  to front of sublist

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Reverse only required segment in-place

-------------------------------------
*/

class Solution {
public:

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || left == right) {
            return head;
        }

        ListNode* dummyNode = new ListNode(0);

        dummyNode->next = head;

        // Reach node before reversal
        ListNode* previousNode = dummyNode;

        for(int i = 1; i < left; i++) {

            previousNode = previousNode->next;
        }

        ListNode* currentNode = previousNode->next;

        // Reverse sublist
        for(int i = 0; i < right - left; i++) {

            ListNode* nextNode = currentNode->next;

            currentNode->next = nextNode->next;

            nextNode->next = previousNode->next;

            previousNode->next = nextNode;
        }

        return dummyNode->next;
    }
};
