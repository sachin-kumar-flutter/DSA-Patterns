/*
-------------------------------------
🧩 Problem: Happy Number
📂 Category: Fast-Slow Pointers
🧠 Concept: Cycle detection on numbers

⚡ Approach:
- Replace number with sum of squares
  of its digits
- Use Floyd’s cycle detection
- If cycle reaches 1:
    number is happy

⏱️ Time Complexity: O(log n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Fast-slow pointers can detect cycles
  in mathematical transformations

-------------------------------------
*/

class Solution {
public:

    int digitSquareSum(int number) {

        int sum = 0;

        while(number) {

            int digit = number % 10;

            number /= 10;

            sum += digit * digit;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slowPointer = n;
        int fastPointer = n;

        do {

            slowPointer =
                digitSquareSum(slowPointer);

            fastPointer =
                digitSquareSum(
                    digitSquareSum(fastPointer)
                );

        } while(slowPointer != fastPointer);

        return slowPointer == 1;
    }
};
