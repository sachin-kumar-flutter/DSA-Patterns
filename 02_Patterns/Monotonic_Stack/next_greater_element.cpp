/*
🔹 Problem: Next Greater Element I (LeetCode)

🔹 Approach:
- Use a monotonic decreasing stack (store indices of nums2)
- Traverse nums2 and resolve next greater elements
- Use hashmap to track indices of nums1 elements
- When next greater is found, directly fill the answer

🔹 Key Idea:
When current element is greater than stack top,
it becomes the next greater element for that index.

🔹 Time Complexity: O(n)
🔹 Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        // Map nums1 values to their indices
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }

        stack<int> st; // stores indices of nums2
        vector<int> ans(nums1.size(), -1);

        for(int i = 0; i < nums2.size(); i++) {
            // Resolve elements smaller than current
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                if(mp.find(nums2[st.top()]) != mp.end()) {
                    ans[mp[nums2[st.top()]]] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
