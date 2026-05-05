class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        
        int smallest = INT_MAX;
        int largest = INT_MIN;
        
        for (int x : arr) {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
        
        return {smallest, largest};
    }
};
