/*
Problem: Maximum Number of Families (Cinema Seat Allocation)
Platform: LeetCode

Approach:
- Each row has 10 seats, but only seats [2–9] matter for placing a group of 4.
- There are 3 possible seating blocks:
    1. Left block:  [2,3,4,5]
    2. Middle block: [4,5,6,7] (valid across aisle)
    3. Right block: [6,7,8,9]

- Use a hashmap to store reserved seats row-wise.
- For rows with no reservations → directly add 2 groups.
- For reserved rows:
    - Check availability of left, middle, and right blocks.
    - If left & right both free → 2 groups
    - Else if any one block is free → 1 group
    - Else → 0

Time Complexity: O(m)
Space Complexity: O(m)

Author: Sachin
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;
        
        // Store reserved seats row-wise
        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }
        
        int ans = 0;
        
        // Rows with no reservations can have 2 groups
        ans += (n - mp.size()) * 2;
        
        // Process rows with reservations
        for (auto &row : mp) {
            auto &s = row.second;
            
            bool left = true, mid = true, right = true;
            
            // Check left block [2,3,4,5]
            for (int i = 2; i <= 5; i++) {
                if (s.count(i)) {
                    left = false;
                    break;
                }
            }
            
            // Check middle block [4,5,6,7]
            for (int i = 4; i <= 7; i++) {
                if (s.count(i)) {
                    mid = false;
                    break;
                }
            }
            
            // Check right block [6,7,8,9]
            for (int i = 6; i <= 9; i++) {
                if (s.count(i)) {
                    right = false;
                    break;
                }
            }
            
            if (left && right) ans += 2;
            else if (left || mid || right) ans += 1;
        }
        
        return ans;
    }
};
