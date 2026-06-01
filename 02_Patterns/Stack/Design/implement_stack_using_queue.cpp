/*
-------------------------------------
🧩 Problem: Implement Stack using Queue
📂 Category: Stack / Design
🧠 Concept:
- Queue rotation
- LIFO simulation

⚡ Approach:
- Push element into queue
- Rotate existing elements behind it
- Front of queue always represents stack top

⏱️ Time Complexity:
    push() -> O(n)
    pop()  -> O(1)
    top()  -> O(1)

💾 Space Complexity: O(n)

🎯 Key Idea:
- Maintain newest element at queue front

-------------------------------------
*/

class MyStack {
public:

    queue<int> queueData;

    MyStack() {}

    void push(int value) {

        queueData.push(value);
        int currentSize = queueData.size();

        for(int i = 0; i < currentSize - 1; i++) {
            queueData.push(queueData.front());
            queueData.pop();
        }
    }

    int pop() {

        int topElement = queueData.front();
        queueData.pop();
        return topElement;
    }

    int top() return queueData.front();

    bool empty() return queueData.empty();
};
