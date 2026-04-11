/*
Problem: Count Subarrays with Sum = 0

Approach:
- Use Prefix Sum + HashMap
- Store frequency of prefix sums
- If same prefix sum appears again, it means the subarray between them has sum = 0

Key Idea:
If prefixSum[i] == prefixSum[j], then subarray (i+1 to j) has sum = 0

Steps:
1. Traverse array and keep updating prefixSum
2. Check if prefixSum already exists in map
   → If yes, add its frequency to answer
3. Update map with current prefixSum

Important:
- Initialize map[0] = 1 to handle subarrays starting from index 0

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        long long prefixSum=0;
        int ans=0;
        
        unordered_map<long long,int> map;
        map[0]=1;
        for(int i=0;i<arr.size();i++){
            prefixSum+=arr[i];
            
            if(map.count(prefixSum)) ans+=map[prefixSum];
            map[prefixSum]++;
        }
        
        return ans;
    }
};
