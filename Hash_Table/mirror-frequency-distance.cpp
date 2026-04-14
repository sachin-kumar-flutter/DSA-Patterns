/*
Problem: Mirror Frequency Distance

Approach:
1. Count frequency of each character using a hash map.
2. For each unique character 'c':
   - Find its mirror character:
        Letters: mirror = 'z' - (c - 'a')
        Digits:  mirror = '9' - (c - '0')
   - Compute absolute difference:
        |freq(c) - freq(mirror)|
3. Use a visited set to avoid counting mirror pairs twice
   (since (c, m) and (m, c) are same).

Key Insight:
- Treat mirror characters as pairs and process each pair only once.

Time Complexity: O(n)
Space Complexity: O(1) (max 36 unique characters)

Pattern:
- Frequency counting + symmetric mapping + avoid double counting
*/

class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> freq;

        // Count frequency
        for(char ch : s) freq[ch]++;

        unordered_set<char> visited;
        int ans = 0;

        for(auto &p : freq){
            char c = p.first;

            if(visited.count(c)) continue;

            char mirror;

            // Find mirror character
            if(isalpha(c)) mirror = 'z' - (c - 'a');
            else mirror = '9' - (c - '0');

            int f1 = p.second;
            int f2 = freq.count(mirror) ? freq[mirror] : 0;

            ans += abs(f1 - f2);

            // Mark both as visited
            visited.insert(c);
            visited.insert(mirror);
        }

        return ans;
    }
};
