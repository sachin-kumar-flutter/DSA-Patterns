/*
Problem: Intersection of Two Sorted Arrays (Distinct Elements)

Pattern: Two Pointers on Sorted Arrays

Approach:
- Use two pointers i and j to traverse both arrays
- If a[i] < b[j], move i
- If a[i] > b[j], move j
- If equal:
    - Add element to result
    - Move both pointers
    - Skip duplicates in both arrays

Key Insight:
Since arrays are sorted, we can efficiently find intersection
in O(n + m) time without using extra space like hash sets.

Time Complexity: O(n + m)
Space Complexity: O(1) (excluding output)

Why Important:
This is a fundamental pattern used in merging, intersection,
union, and duplicate removal problems.
*/
class Solution{
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        
        int i=0,j=0;
        vector<int> ans;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]) i++;
            else if(a[i]>b[j]) j++;
            else{
                ans.push_back(a[i]);
                i++;
                j++;
                while(i<a.size() && a[i]==a[i-1]) i++;
                while(j<b.size() && b[j]==b[j-1]) j++;
            }
        }
        
        return ans;
        
    }
};
