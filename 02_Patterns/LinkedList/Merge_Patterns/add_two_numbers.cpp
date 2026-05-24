/*
-------------------------------------
🧩 Problem: Add Two Numbers
📂 Category: Linked List / Simulation
🧠 Concept: Digit-wise addition

⚡ Approach:
- Traverse both linked lists together
- Add digits along with carry
- Create result list node-by-node

⏱️ Time Complexity: O(max(n, m))
💾 Space Complexity: O(max(n, m))

🎯 Key Idea:
- Simulate elementary addition using linked lists

-------------------------------------
*/

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-1);
        ListNode* tailPointer = dummyNode;
        int carry = 0;
        while(list1 || list2 || carry) {

            int sum = carry;

            // Add digit from first list
            if(list1) {
                sum += list1->val;
                list1 = list1->next;
            }
            // Add digit from second list
            if(list2) {
                sum += list2->val;
                list2 = list2->next;
            }
            // Update carry
            carry = sum / 10;

            // Create current digit node
            tailPointer->next = new ListNode(sum % 10);

            tailPointer = tailPointer->next;
        }

        return dummyNode->next;
    }
};
