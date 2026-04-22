/*
Problem: Next Greater Node In Linked List

Approach:
---------
1. Convert the linked list into an array.
   - Linked list does not support random access, so array simplifies traversal.

2. Use a Monotonic Decreasing Stack:
   - Stack stores indices of elements.
   - Traverse the array from left to right.
   - For each element:
       -> While stack is not empty AND current element is greater than element at stack top:
            - Update result for that index
            - Pop from stack
       -> Push current index into stack

3. Remaining indices in stack have no greater element → default 0

Why this works:
---------------
- Each element is pushed and popped at most once → O(n)
- This is a classic "Next Greater Element to the right" pattern

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;

        // Step 1: Convert Linked List → Array
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> st; // stores indices

        // Step 2: Monotonic Stack
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};
