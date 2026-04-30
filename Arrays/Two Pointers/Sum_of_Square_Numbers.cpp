class Solution {
public:
    bool judgeSquareSum(int c) {
        // Two-pointer approach
        long long a = 0;
        long long b = sqrt(c);

        while (a <= b) {
            long long sum = a * a + b * b;

            if (sum == c) {
                return true;   // Found a valid pair
            } 
            else if (sum < c) {
                a++;           // Increase sum
            } 
            else {
                b--;           // Decrease sum
            }
        }

        return false;  // No such pair exists
    }
};
