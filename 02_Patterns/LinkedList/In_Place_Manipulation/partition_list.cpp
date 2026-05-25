/*
-------------------------------------
🧩 Problem: Partition List
📂 Category: Linked List / Rearrangement
🧠 Concept: Stable partitioning

⚡ Approach:
- Maintain:
    smaller list
    greater/equal list
- Traverse original list once
- Connect both lists at the end

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Preserve relative order while partitioning

-------------------------------------
*/

class Solution {
public:

    ListNode* partition(ListNode* head, int x) {

        // Dummy nodes for partitions
        ListNode* smallerDummy = new ListNode(-1);
        ListNode* greaterDummy = new ListNode(-1);
        ListNode* smallerTail = smallerDummy, * greaterTail = greaterDummy;

        while(head) {
          
            if(head->val < x) {
              
                smallerTail->next = head;
                smallerTail = smallerTail->next;
            }
            else {
              
                greaterTail->next = head;
                greaterTail = greaterTail->next;
            }
            head = head->next;
        }

        // End greater list
        greaterTail->next = NULL;

        // Connect partitions
        smallerTail->next = greaterDummy->next;

        return smallerDummy->next;
    }
};
