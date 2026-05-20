/*
-------------------------------------
🧩 Problem: Palindrome Linked List
📂 Category: Linked List / Fast-Slow Pointers
🧠 Concept: Middle + reverse + compare

⚡ Approach:
- Find middle using fast/slow pointers
- Reverse second half
- Compare both halves node by node

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Reverse only half of the linked list

-------------------------------------
*/

class Solution {
public:

    bool isPalindrome(ListNode* head) {

        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        // Find middle node
        while(fastPointer->next &&
              fastPointer->next->next) {

            slowPointer =
                slowPointer->next;

            fastPointer =
                fastPointer->next->next;
        }

        // Reverse second half
        ListNode* secondHalf =
            reverseList(slowPointer->next);

        ListNode* firstHalf = head;

        // Compare both halves
        while(secondHalf) {

            if(firstHalf->val !=
               secondHalf->val) {

                return false;
            }

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode* head) {

        ListNode* previousNode = NULL;

        while(head) {

            ListNode* nextNode =
                head->next;

            head->next = previousNode;

            previousNode = head;

            head = nextNode;
        }

        return previousNode;
    }
};
