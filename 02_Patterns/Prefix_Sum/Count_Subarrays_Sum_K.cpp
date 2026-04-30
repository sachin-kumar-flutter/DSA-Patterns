/*
Problem: Count Subarrays with Sum = K

Approach:
- Use Prefix Sum + HashMap
- Instead of checking same prefix sum, check for (prefixSum - k)

Key Idea:
If (prefixSum - k) exists in map, it means a subarray with sum = k exists

Steps:
1. Traverse array and keep updating prefixSum
2. Check if (prefixSum - k) exists in map
   → If yes, add its frequency to answer
3. Update map with current prefixSum

Important:
- Initialize map[0] = 1 to handle subarrays starting from index 0

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int prefixSum=0,ans=0;
        unordered_map<int,int> map;
        
        map[0]=1;
        
        for(int i=0;i<arr.size();i++){
            prefixSum+=arr[i];
            
            if(map.count(prefixSum-k)) ans+=map[prefixSum-k];
            map[prefixSum]++;
        }
        
        return ans;
    }
};
