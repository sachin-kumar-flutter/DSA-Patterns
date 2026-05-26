/*
-------------------------------------
🧩 Problem: LRU Cache
📂 Category: Advanced Linked List
🧠 Concept:
- HashMap + Doubly Linked List

⚡ Approach:
- HashMap provides O(1) access
- Doubly linked list maintains usage order
- Most recently used node stays near head
- Least recently used node stays near tail

⏱️ Time Complexity:
    get() -> O(1)
    put() -> O(1)

💾 Space Complexity: O(capacity)

🎯 Key Idea:
- Combine fast lookup with fast deletion

-------------------------------------
*/

class LRUCache {
public:

    struct DLinkedNode {

        int key;
        int value;
        DLinkedNode* prev;
        DLinkedNode* next;

        DLinkedNode(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    int capacity;
    DLinkedNode* head;
    DLinkedNode* tail;
    unordered_map<int, DLinkedNode*> cache;

    // Remove node from list
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    // Insert node after head
    void addToHead(DLinkedNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    LRUCache(int capacity) {

        this->capacity = capacity;
        head = new DLinkedNode(-1, -1);
        tail = new DLinkedNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(!cache.count(key)) {
            return -1;
        }

        DLinkedNode* node = cache[key];
        // Move to front
        removeNode(node);
        addToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        // Update existing key
        if(cache.count(key)) {
            DLinkedNode* node = cache[key];
            node->value = value;
            removeNode(node);
            addToHead(node);
        }

        // Insert new key
        else {
            DLinkedNode* node = new DLinkedNode(key, value);
            addToHead(node);
            cache[key] = node;
            // Remove LRU node
            if(cache.size() > capacity) {
                DLinkedNode* lruNode = tail->prev;
                removeNode(lruNode);
                cache.erase(lruNode->key);
                delete lruNode;
            }
        }
    }
};
