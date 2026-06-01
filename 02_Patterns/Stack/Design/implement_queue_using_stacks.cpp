/*
-------------------------------------
🧩 Problem: Implement Queue using Stacks
📂 Category: Stack / Design
🧠 Concept:
- Two-stack simulation
- FIFO using LIFO

⚡ Approach:
- inbox stores new elements
- outbox serves queue operations
- Transfer only when needed

⏱️ Time Complexity:
    push() -> O(1)
    pop()  -> Amortized O(1)
    peek() -> Amortized O(1)
    empty() -> O(1)

💾 Space Complexity: O(n)

🎯 Key Idea:
- Reverse order twice using stacks
  to simulate queue behavior

-------------------------------------
*/

class MyQueue {
public:

    stack<int> inbox;
    stack<int> outbox;

    MyQueue() {}

    // Transfer elements only when needed
    void transfer() {

        if(outbox.empty()) {
          while(!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }

    // Insert element at rear
    void push(int value) inbox.push(value);

    // Remove front element
    int pop() {

        transfer();
        int frontElement = outbox.top();
        outbox.pop();
        return frontElement;
    }

    // Get front element
    int peek() {

        transfer();
        return outbox.top();
    }

    // Check if queue is empty
    bool empty() return inbox.empty() && outbox.empty();
};

/**
 * Your MyQueue object will be instantiated
 * and called as such:
 *
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
