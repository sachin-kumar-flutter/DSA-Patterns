/*
Problem: Longest Consecutive Sequence (LeetCode 128)

Idea:
The goal is to find the length of the longest sequence of consecutive integers
in an unsorted array in O(n) time.

Sorting would take O(n log n), so we use a hash-based approach to achieve O(n).

Approach:
1. Insert all elements into an unordered_set for O(1) lookup.
2. Iterate through each element:
   - Only start counting when the current number is the beginning of a sequence.
     (i.e., num - 1 is NOT present in the set)
3. From the starting element, keep checking for consecutive numbers (num+1, num+2...)
4. Track the length of the sequence and update the maximum.

Key Insight:
Each element is processed at most once, ensuring O(n) time complexity.

Time Complexity:
O(n) average case

Space Complexity:
O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for(int num : s){
            if(s.find(num - 1) == s.end()){
                int curr = num;
                int count = 0;

                while(s.find(curr) != s.end()){
                    count++;
                    curr++;
                }

                ans = max(ans, count);
            }
        }
        return ans;
    }
};
