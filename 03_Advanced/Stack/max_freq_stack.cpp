/*
-------------------------------------
🧩 Problem: Maximum Frequency Stack
📂 Category: Stack / Design
🧠 Concept:
- Frequency tracking
- Stack grouping

⚡ Approach:
- freq[val] stores frequency
- group[freq] stores stack of values
  having that frequency
- maxFreq tracks highest frequency

⏱️ Time Complexity:
    push() -> O(1)
    pop()  -> O(1)

💾 Space Complexity: O(n)

🎯 Key Idea:
- Elements with same frequency
  behave like a stack

-------------------------------------
*/

class FreqStack {
public:

    // value -> frequency
    unordered_map<int, int> frequencyMap;
    // frequency -> stack of values
    unordered_map<int, stack<int>> frequencyGroups;
    int maximumFrequency = 0;

    FreqStack() {}

    void push(int value) {

        int currentFrequency = ++frequencyMap[value];

        maximumFrequency = max(maximumFrequency, currentFrequency);
        frequencyGroups[currentFrequency].push(value);
    }

    int pop() {

        int value = frequencyGroups[maximumFrequency].top();

        frequencyGroups[maximumFrequency].pop();
        frequencyMap[value]--;

        // Reduce max frequency if needed
        if(frequencyGroups[maximumFrequency].empty()) maximumFrequency--;

        return value;
    }
};

/**
 * Your FreqStack object will be
 * instantiated and called as such:
 *
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
