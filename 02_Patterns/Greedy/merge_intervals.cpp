class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by start time (default sort on vector<int> compares
        // element-wise, so this sorts by [0] first, then [1] as tiebreaker)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);   // start with the first interval as our base

        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval's start is within (or touching) the
            // end of the last merged interval, they overlap — merge them
            // by extending the end to the farther of the two ends
            if (result.back()[1] >= intervals[i][0]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            // Otherwise, no overlap — this is a new, separate interval
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
