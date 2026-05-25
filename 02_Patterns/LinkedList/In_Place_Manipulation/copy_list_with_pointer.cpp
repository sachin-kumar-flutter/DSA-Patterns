/*
-------------------------------------
🧩 Problem: Copy List with Random Pointer
📂 Category: Advanced Linked List
🧠 Concept: Deep copy with random pointers

⚡ Approach:
1. Create clone node for each original node
2. Store mapping:
      original → clone
3. Reconnect:
      next pointers
      random pointers

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Hashmap preserves original-clone relationships

-------------------------------------
*/

class Solution {
public:

    Node* copyRandomList(Node* head) {

        if(!head) return NULL;

        unordered_map<Node*, Node*> nodeMap;

        Node* currentNode = head;

        // Create clone nodes
        while(currentNode) {

            nodeMap[currentNode] = new Node(currentNode->val);
            currentNode = currentNode->next;
        }
        currentNode = head;
        // Connect next and random pointers
        while(currentNode) {

            nodeMap[currentNode]->next = nodeMap[currentNode->next];
            nodeMap[currentNode]->random = nodeMap[currentNode->random];
            currentNode = currentNode->next;
        }

        return nodeMap[head];
    }
};
