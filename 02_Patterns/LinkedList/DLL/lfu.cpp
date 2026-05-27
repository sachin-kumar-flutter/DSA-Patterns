/*
---------------------------------------------------
🧩 Problem: LFU Cache
📂 Category: Advanced Linked List / Design
🧠 Concepts Used:
- HashMap
- Doubly Linked List
- Frequency Tracking
- LRU inside LFU

⚡ Core Idea:
- keyMap: key -> node mapping

- freqMap:frequency -> doubly linked list

- Every frequency maintains: most recently used order

- minFreq stores:current minimum frequency

⏱️ Time Complexity:
    get()  -> O(1)
    put()  -> O(1)

💾 Space Complexity:
    O(capacity)

---------------------------------------------------
*/

struct Node {

    int key, value, freq;
    Node* prev,* next;

    // New node starts with frequency 1
    Node(int k, int v) : key(k), value(v), freq(1), prev(NULL), next(NULL) {}
};

struct FreqList {

    Node* head,* tail;
    int size;

    FreqList() : size(0) {
        // Dummy head and tail nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // Insert node right after head
    // (Most Recently Used position)
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    // Remove node from linked list
    void removeNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        size--;
    }

    // Remove least recently used node
    // from current frequency list
    Node* removeLRU() {
        Node* lruNode = tail->prev;
        removeNode(lruNode);
        return lruNode;
    }
};

class LFUCache {

public:
    int capacity;
    // Tracks minimum frequency
    int minFreq;
    // key -> node
    unordered_map<int, Node*> keyMap;
    // frequency -> list of nodes
    unordered_map<int, FreqList*> freqMap;
    /*
    ----------------------------------------
    🔄 Update frequency of node

    Steps:
    1. Remove node from old freq list
    2. Increase frequency
    3. Add node to new freq list
    4. Update minFreq if needed
    ----------------------------------------
    */
    void updateFreq(Node* node) {

        int currentFreq = node->freq;
        // Remove from old frequency list
        freqMap[currentFreq]->removeNode(node);
        /*
        If current minimum frequency list
        becomes empty, increase minFreq
        */
        if(currentFreq == minFreq && freqMap[currentFreq]->size == 0) minFreq++;
        // Increase frequency
        node->freq++;
        // Create new frequency list if absent
        if(!freqMap.count(node->freq)) freqMap[node->freq] = new FreqList();
        // Add node to new frequency list
        freqMap[node->freq]->addToHead(node);
    }

    /*
    ----------------------------------------
    🏗️ Constructor
    ----------------------------------------
    */
    LFUCache(int cap) : capacity(cap), minFreq(0) {}
    /*
    ----------------------------------------
    🔍 GET Operation

    - Return value if key exists
    - Update node frequency
    ----------------------------------------
    */
    int get(int key) {
        // Key not present
        if(!keyMap.count(key)) return -1;
        Node* node = keyMap[key];
        // Update usage frequency
        updateFreq(node);
        return node->value;
    }

    /*
    ----------------------------------------
    ➕ PUT Operation

    Cases:
    1. Capacity = 0
    2. Key already exists
    3. Insert new key
    4. Remove LFU node if full
    ----------------------------------------
    */
    void put(int key, int value) {
        // Edge case
        if(capacity == 0) return;

        // Update existing key
        if(keyMap.count(key)) {
            keyMap[key]->value = value;
            updateFreq(keyMap[key]);
        }
        // Insert new key
        else {
            // Cache full -> remove LFU node
            if(keyMap.size() >= capacity) {
                Node* lruNode = freqMap[minFreq]->removeLRU();
                keyMap.erase(lruNode->key);
                delete lruNode;
            }

            // Create new node
            Node* node = new Node(key, value);
            keyMap[key] = node;
            // Ensure freq=1 list exists
            if(!freqMap.count(1)) freqMap[1] = new FreqList();
            // Insert into frequency 1 list
            freqMap[1]->addToHead(node);
            // New node always has min frequency
            minFreq = 1;
        }
    }
};
