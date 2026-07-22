class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        int n = intervals.size();

        // Sort intervals by their END time.
        // This is the key greedy choice: an interval that ends earlier
        // leaves more room for future intervals to fit without overlapping.
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        // Greedily pick the first interval (smallest end time) as our baseline
        int count = 1;                  // count of non-overlapping intervals we can keep
        int lastUsed = intervals[0][1]; // end time of the last kept interval

        for (int i = 1; i < n; i++) {
            // If current interval starts after (or when) the last kept interval ends,
            // there's no overlap — keep it and update the boundary
            if (lastUsed <= intervals[i][0]) {
                count++;
                lastUsed = intervals[i][1];
            }
            // else: current interval overlaps with the last kept one,
            // so we skip it (equivalent to "removing" it)
        }

        // Minimum removals = total intervals - maximum non-overlapping intervals we can keep
        return n - count;
    }
};
