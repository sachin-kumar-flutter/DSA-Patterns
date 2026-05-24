/*
-------------------------------------
🧩 Problem: Merge K Sorted Lists
📂 Category: Advanced Linked List
🧠 Concept: Bottom-up pairwise merging

⚡ Approach:
- Merge lists in pairs
- Reduce total lists after each round
- Continue until one list remains

⏱️ Time Complexity: O(N log k)
💾 Space Complexity: O(1)

Where:
- N = total nodes
- k = number of linked lists

🎯 Key Idea:
- Repeated pairwise merging reduces complexity

-------------------------------------
*/

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return NULL;

        int totalLists = lists.size();

        // Merge lists in pairs
        while(totalLists > 1) {
            for(int i = 0; i < totalLists / 2; i++) lists[i] = mergeTwoLists(lists[i], lists[totalLists - 1 - i]);

            // Remaining lists after merging
            totalLists = (totalLists + 1) / 2;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-1);

        ListNode* tailPointer = dummyNode;

        while(list1 && list2) {

            if(list1->val <= list2->val) {
                tailPointer->next = list1;
                list1 = list1->next;
            }
            else {
                tailPointer->next = list2;
                list2 = list2->next;
            }
            tailPointer = tailPointer->next;
        }

        // Attach remaining nodes
        tailPointer->next = list1 ? list1 : list2;

        return dummyNode->next;
    }
};
