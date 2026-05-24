/*
-------------------------------------
🧩 Problem: Merge K Sorted Lists
📂 Category: Advanced Linked List
🧠 Concept: Min Heap + K-way Merge

⚡ Approach:
- Store smallest node from each list
  inside min heap
- Repeatedly extract minimum node
- Push next node from extracted list

⏱️ Time Complexity: O(N log k)
💾 Space Complexity: O(k)

Where:
- N = total nodes
- k = number of linked lists

🎯 Key Idea:
- Heap efficiently tracks global minimum

-------------------------------------
*/

class Solution {
public:

    ListNode* mergeKLists(
        vector<ListNode*>& lists) {

        if(lists.empty()) return NULL;

        // Min heap comparator
        auto comp = [](ListNode* a, ListNode* b) {
          return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minHeap(comp);

        // Push first node of each list
        for(auto listHead : lists) if(listHead) minHeap.push(listHead);

        ListNode* dummyNode = new ListNode(-1);
        ListNode* tailPointer = dummyNode;

        while(!minHeap.empty()) {

            ListNode* smallestNode = minHeap.top();
            minHeap.pop();
            tailPointer->next = smallestNode;
            tailPointer = tailPointer->next;

            // Push next node
            if(smallestNode->next) minHeap.push(smallestNode->next);
        }

        return dummyNode->next;
    }
};
