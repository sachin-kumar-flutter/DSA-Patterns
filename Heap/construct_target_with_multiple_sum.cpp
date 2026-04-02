// Problem: Construct Target Array With Multiple Sums
// Pattern: Greedy + Max Heap + Mathematical Reduction
// Difficulty: Hard

// Key Idea:
// Instead of building the target array forward, we reverse the process.
// At each step, we focus on the largest element and try to reconstruct
// its previous value using the sum of the remaining elements.

// Intuition:
// - Let maxVal be the largest element
// - Let rest = totalSum - maxVal
// - Previously, maxVal was formed by adding rest multiple times
// - So we reduce maxVal efficiently using modulo:
//     maxVal = maxVal % rest

// Why Modulo?
// Repeated subtraction would be too slow, so we use modulo
// to jump directly to the previous valid state.

// Edge Cases:
// - If rest == 0 → invalid (cannot reduce further)
// - If maxVal <= rest → invalid state
// - If rest == 1 → always possible (can reduce everything to 1)

// Approach:
// - Use a max heap to always access the largest element
// - Keep updating total sum dynamically

// Time Complexity: O(n log n)
// Space Complexity: O(n)

// Tags: Greedy, Heap, Math, Reverse Thinking



class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> pq;

        // Initialize heap and total sum
        for (int x : target) {
            sum += x;
            pq.push(x);
        }

        while (true) {
            long long mx = pq.top();
            pq.pop();

            long long rest = sum - mx;

            // Base cases
            if (mx == 1 || rest == 1)
                return true;

            // Invalid cases
            if (rest == 0 || rest >= mx)
                return false;

            // Reduce the largest element
            long long prev = mx % rest;

            if (prev == 0)
                return false;

            // Update sum and heap
            sum = rest + prev;
            pq.push(prev);
        }
    }
};
