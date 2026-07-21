class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort greed factors (g) and cookie sizes (s) in ascending order
        // so we can match the smallest cookie to the least greedy child first
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, ans = 0;   // i -> pointer for children, j -> pointer for cookies

        while (i < g.size() && j < s.size()) {
            // If current cookie is big enough to satisfy current child,
            // assign it and move to the next child and next cookie
            if (s[j] >= g[i]) {
                i++; j++; ans++;
            }
            // Otherwise, this cookie is too small for the child,
            // try the next (bigger) cookie
            else j++;
        }

        return ans;   // total number of content children
    }
};
