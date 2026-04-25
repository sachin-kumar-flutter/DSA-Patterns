class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;

        // Step 1: Sort the array
        // Reason: Minimum absolute difference will always be between adjacent elements in sorted order
        sort(arr.begin(), arr.end());

        // Step 2: Find the minimum absolute difference
        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        // Step 3: Collect all pairs having this minimum difference
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};
