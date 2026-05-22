/*
-------------------------------------
🧩 Problem: Merge K Sorted Linked Lists
📂 Category: Advanced Linked List
🧠 Concept: Divide and conquer merging

⚡ Approach:
- Recursively divide list array
- Merge smaller groups first
- Reuse merge-two-lists logic

⏱️ Time Complexity: O(N log k)
💾 Space Complexity: O(log k)

Where:
- N = total nodes
- k = number of linked lists

🎯 Key Idea:
- Reduce repeated merging using divide & conquer

-------------------------------------
*/

class Solution {
public:

    Node* mergeKLists(vector<Node*>& lists) {

        if(lists.empty()) {
            return NULL;
        }

        return mergeRange(
            0,
            lists.size() - 1,
            lists
        );
    }

    Node* mergeRange(int left,
                     int right,
                     vector<Node*>& lists) {

        // Single list
        if(left == right) {
            return lists[left];
        }

        int mid =
            left + (right - left) / 2;

        Node* leftMerged =
            mergeRange(left, mid, lists);

        Node* rightMerged =
            mergeRange(mid + 1,
                       right,
                       lists);

        return mergeTwoLists(
            leftMerged,
            rightMerged
        );
    }

    Node* mergeTwoLists(Node* list1,
                        Node* list2) {

        Node* dummyNode =
            new Node(-1);

        Node* tailPointer =
            dummyNode;

        while(list1 && list2) {

            if(list1->data <= list2->data) {

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
