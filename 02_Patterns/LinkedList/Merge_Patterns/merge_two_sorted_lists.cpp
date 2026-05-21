/*
-------------------------------------
🧩 Problem: Merge Two Sorted Lists
📂 Category: Linked List / Merge Patterns
🧠 Concept: Two-pointer merging

⚡ Approach:
- Use dummy node for easy handling
- Compare nodes from both lists
- Attach smaller node to merged list
- Append remaining nodes

⏱️ Time Complexity: O(n + m)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Build merged list using tail pointer

-------------------------------------
*/

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1,
                            ListNode* list2) {

        ListNode* dummyNode =
            new ListNode(-1);

        ListNode* tailPointer =
            dummyNode;

        while(list1 && list2) {

            if(list1->val < list2->val) {

                tailPointer->next = list1;

                list1 = list1->next;
            }

            else {

                tailPointer->next = list2;

                list2 = list2->next;
            }

            tailPointer =
                tailPointer->next;
        }

        // Attach remaining nodes
        if(list1) {

            tailPointer->next = list1;
        }

        else {

            tailPointer->next = list2;
        }

        return dummyNode->next;
    }
};
