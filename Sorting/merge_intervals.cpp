class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Step 1: Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Initialize with first interval
        int start = intervals[0][0];
        int end = intervals[0][1];

        // Step 2: Traverse and merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            
            // If overlapping, extend the current interval
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } 
            else {
                // No overlap → push previous interval
                ans.push_back({start, end});

                // Start a new interval
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Step 3: Push the last interval
        ans.push_back({start, end});

        return ans;
    }
};
