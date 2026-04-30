class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Max heap (default in C++)
        priority_queue<int> pq;

        // Push all elements into heap
        for(int x : nums) {
            pq.push(x);
        }

        // Remove top (largest) k-1 elements
        // After that, kth largest will be at top
        k--;
        while(k--) {
            pq.pop();
        }

        // Return kth largest element
        return pq.top();
    }
};
