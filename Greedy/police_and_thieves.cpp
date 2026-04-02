// Problem: Police and Thieves
// Pattern: Greedy + Two Pointers
// Difficulty: Medium

// Key Idea:
// We want to maximize the number of thieves caught.
// Each policeman can catch at most one thief within distance k.

// Approach:
// - Store indices of policemen and thieves separately
// - Use two pointers to match them greedily
// - Always try to match the closest available pair

// Intuition:
// - If distance <= k → valid match → move both pointers
// - If thief is too far left → move thief pointer
// - If policeman is too far left → move police pointer

// Why Greedy?
// Matching the closest valid pairs ensures maximum number of matches
// without wasting any policeman or thief.

// Time Complexity: O(n)
// Space Complexity: O(n)

// Tags: Greedy, Two Pointers, Array
