/*
-------------------------------------
🧩 Problem: Linked List Cycle
📂 Category: Linked List / Fast-Slow Pointers
🧠 Concept: Floyd’s Cycle Detection

⚡ Approach:
- Slow pointer moves 1 step
- Fast pointer moves 2 steps
- If cycle exists:
    both pointers eventually meet

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Different traversal speeds expose cycles

-------------------------------------
*/

class Solution {
public:

    bool hasCycle(ListNode* head) {

        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer &&
              fastPointer->next) {

            slowPointer =
                slowPointer->next;

            fastPointer =
                fastPointer->next->next;

            // Cycle detected
            if(slowPointer == fastPointer) {
                return true;
            }
        }

        return false;
    }
};
