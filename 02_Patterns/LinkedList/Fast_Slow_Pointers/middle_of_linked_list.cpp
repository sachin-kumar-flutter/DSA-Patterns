/*
-------------------------------------
🧩 Problem: Middle of the Linked List
📂 Category: Linked List / Fast-Slow Pointers
🧠 Concept: Two-pointer traversal

⚡ Approach:
- Move slow pointer by 1 step
- Move fast pointer by 2 steps
- When fast reaches end:
    slow reaches middle

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Different traversal speeds reveal middle node

-------------------------------------
*/

class Solution {
public:

    ListNode* middleNode(ListNode* head) {

        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer &&
              fastPointer->next) {

            slowPointer = slowPointer->next;

            fastPointer =
                fastPointer->next->next;
        }

        return slowPointer;
    }
};
