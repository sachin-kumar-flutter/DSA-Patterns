/*
🔹 Problem: Count Strictly Increasing Subarrays

🔹 Pattern: Segment-Based Counting (Increasing Subarray Pattern)

🔹 Approach:
- Traverse the array and divide it into strictly increasing segments
- For each segment of length k:
      Number of increasing subarrays = k * (k - 1) / 2
- Add contributions of all segments

🔹 Example:
arr = [1, 2, 3, 1, 2]
Segments:
[1,2,3] → length = 3 → subarrays = 3
[1,2]   → length = 2 → subarrays = 1
Total = 4

🔹 Time Complexity: O(n)
🔹 Space Complexity: O(1)

🔹 Why Important?
- Common pattern in array problems
- Useful for monotonic sequences and sliding window optimizations
*/

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int ans=0;
        int count=1;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]){
                ans+=(count*(count-1))/2;
                count=1;
            }
            else count++;
        }
        ans+=(count*(count-1))/2;
        
        return ans;
    }
};
