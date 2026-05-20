/*
-------------------------------------
🧩 Problem: Linked List Cycle II
📂 Category: Linked List / Fast-Slow Pointers
🧠 Concept: Floyd’s Cycle Detection

⚡ Approach:
- Detect cycle using fast & slow pointers
- Once they meet:
    move slow to head
- Move both pointers one step at a time
- Meeting point becomes cycle start

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Distance mathematics inside the cycle

-------------------------------------
*/

class Solution {
public:

    ListNode* detectCycle(ListNode* head) {

        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        // Detect cycle
        while(fastPointer &&
              fastPointer->next) {

            slowPointer =
                slowPointer->next;

            fastPointer =
                fastPointer->next->next;

            // Collision point
            if(slowPointer == fastPointer) {

                slowPointer = head;

                // Find cycle entry
                while(slowPointer != fastPointer) {

                    slowPointer =
                        slowPointer->next;

                    fastPointer =
                        fastPointer->next;
                }

                return slowPointer;
            }
        }

        return NULL;
    }
};
