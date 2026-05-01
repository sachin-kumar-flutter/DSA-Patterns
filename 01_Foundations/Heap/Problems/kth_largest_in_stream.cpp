// Problem: Kth Largest Element in a Stream
// Pattern: Heap (Top K Elements)
// Approach: Maintain a Min Heap of size K
// Time Complexity: O(n log k)
// Space Complexity: O(k)


/*
Key Idea:
- Maintain only top K largest elements using a Min Heap.
- The root of the heap always represents the Kth largest element.

Why Min Heap?
- It keeps the smallest among top K at the top.
- If a new element is larger, it replaces the smallest.

This avoids sorting at every step and reduces complexity from O(n^2 log n) to O(n log k).
*/


class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min Heap
        vector<int> ans;

        for(int i = 0; i < arr.size(); i++) {

            // Step 1: Fill heap until size k
            if(pq.size() < k) {
                pq.push(arr[i]);
            }
            // Step 2: Maintain top K elements
            else if(arr[i] > pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }

            // Step 3: Store result
            if(pq.size() < k) {
                ans.push_back(-1);
            } else {
                ans.push_back(pq.top()); // Kth largest
            }
        }

        return ans;
    }
};
