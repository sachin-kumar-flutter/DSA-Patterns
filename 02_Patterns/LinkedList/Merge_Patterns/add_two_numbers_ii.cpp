/*
-------------------------------------
🧩 Problem: Add Two Numbers II
📂 Category: Advanced Linked List
🧠 Concept: Reverse-order simulation using stacks

⚡ Approach:
- Push digits into stacks
- Process from least significant digit
- Build answer from front using head insertion

⏱️ Time Complexity: O(n + m)
💾 Space Complexity: O(n + m)

🎯 Key Idea:
- Stacks simulate reverse traversal

-------------------------------------
*/

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {

        stack<int> stack1, stack2;

        // Store digits of first list
        while(list1) {
            stack1.push(list1->val);
            list1 = list1->next;
        }
        // Store digits of second list
        while(list2) {
            stack2.push(list2->val);
            list2 = list2->next;
        }
        int carry = 0;
        ListNode* head = NULL;
      
        while(!stack1.empty() || !stack2.empty() || carry) {
            int sum = carry;
            // Add digit from first stack
            if(!stack1.empty()) {
                sum += stack1.top();
                stack1.pop();
            }
            // Add digit from second stack
            if(!stack2.empty()) {
                sum += stack2.top();
                stack2.pop();
            }
            carry = sum / 10;
            // Create new front node
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
