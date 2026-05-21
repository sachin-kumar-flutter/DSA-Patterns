/*
-------------------------------------
🧩 Problem: Reverse Nodes in K Group
📂 Category: Linked List / Reversal
🧠 Concept: Segment-wise reversal

⚡ Approach:
- Check whether k nodes exist
- Reverse current group
- Recursively process remaining list
- Connect reversed groups

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n/k) recursion stack

🎯 Key Idea:
- Reverse linked list in fixed-size chunks

-------------------------------------
*/

class Solution {
public:

    Node* reverseKGroup(Node* head, int k) {

        // Empty list or no reversal needed
        if(!head || k == 1) {
            return head;
        }

        Node* temp = head;

        // Check if k nodes are available
        for(int i = 0; i < k; i++) {

            if(temp == NULL) {
                return head;
            }

            temp = temp->next;
        }

        // Reverse current group
        Node* currentNode = head;
        Node* previousNode = NULL;

        for(int i = 0; i < k; i++) {

            Node* nextNode =
                currentNode->next;

            currentNode->next =
                previousNode;

            previousNode = currentNode;

            currentNode = nextNode;
        }

        // Connect remaining groups
        head->next =
            reverseKGroup(currentNode, k);

        return previousNode;
    }
};
