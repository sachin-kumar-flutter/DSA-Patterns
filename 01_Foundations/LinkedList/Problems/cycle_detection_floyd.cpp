/*
-----------------------------------------
Problem: Detect Cycle in Linked List
Approach: Floyd’s Cycle Detection Algorithm (Tortoise & Hare)
-----------------------------------------

Idea:
- Use two pointers:
    slow -> moves 1 step
    fast -> moves 2 steps

- If there is NO cycle:
    fast will reach NULL

- If there IS a cycle:
    fast will eventually meet slow inside the loop

Why it works:
- Fast pointer moves faster than slow
- In a cycle, fast keeps closing the gap
- Hence, they must meet at some point

Time Complexity: O(n)
Space Complexity: O(1)
-----------------------------------------
*/
