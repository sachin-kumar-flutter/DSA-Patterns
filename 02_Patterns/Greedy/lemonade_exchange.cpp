class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Track available change: $5 and $10 notes
        // (we never need to track $20 notes since we can't give them as change)
        int five = 0, ten = 0;

        for (int x : bills) {
            if (x == 5) {
                // Customer paid exactly $5, no change needed
                five++;
            }
            else if (x == 10) {
                // Customer paid $10, need to give back $5
                if (!five) return false;   // no $5 note available, can't give change
                else {
                    five--;   // use one $5 note as change
                    ten++;    // add the $10 note to our register
                }
            }
            else {
                // Customer paid $20, need to give back $15 in change
                // Greedy choice: prefer using a $10 + $5 note over three $5 notes,
                // since $10 notes are less flexible (only useful for $15 change)
                if (ten && five) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else return false;   // not enough change available
            }
        }

        return true;
    }
};
