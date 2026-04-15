#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
🔹 Problem: Next Permutation

🔹 Goal:
Given an array, rearrange it into the next lexicographically
greater permutation. If such arrangement is not possible,
convert it into the smallest possible order (ascending).

------------------------------------------------------------
🔹 Approach (3 Steps):

1. Find the Breakpoint:
   Traverse from right and find the first index 'i' such that:
   nums[i] < nums[i+1]
   This indicates where the increasing order breaks.

2. Find Next Greater Element:
   Again traverse from right and find index 'j' such that:
   nums[j] > nums[i]
   Swap nums[i] and nums[j]

3. Reverse the Suffix:
   Reverse elements from (i+1) to end to get the smallest order.

------------------------------------------------------------
🔹 Example:
Input:  1 2 5 4 3
Output: 1 3 2 4 5

------------------------------------------------------------
🔹 Edge Case:
If the array is in descending order:
5 4 3 2 1 → 1 2 3 4 5

------------------------------------------------------------
🔹 Time Complexity: O(N)
🔹 Space Complexity: O(1)
------------------------------------------------------------
*/

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find breakpoint
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // Step 2: Find next greater element and swap
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the suffix
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 5, 4, 3};

    nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
