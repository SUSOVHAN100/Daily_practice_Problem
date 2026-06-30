class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        Node* curr = head;

        // STEP 1: Insert copy of each node just after the original node
        // Original: A -> B -> C
        // After this: A -> A' -> B -> B' -> C -> C'
        while (curr != NULL) {
            Node* newNode = new Node(curr->val);
            // Create a new node with same value

            newNode->next = curr->next;
            // New node points to the next of current node

            curr->next = newNode;
            // Insert new node after current node

            curr = newNode->next;
            // Move to the next original node
        }

        // STEP 2: Assign random pointers for copied nodes
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
                // curr->next is copied node
                // curr->random->next is the copied version of random node
            } else {
                curr->next->random = NULL;
                // If original random is NULL, copy random is also NULL
            }

            curr = curr->next->next;
            // Move to next original node
        }

        // STEP 3: Separate original and copied lists
        curr = head;
        Node* copyHead = head->next;   // Head of copied list
        Node* copyCurr = copyHead;

        while (curr != NULL) {
            curr->next = curr->next->next;
            // Restore original list next pointer

            if (copyCurr->next != NULL) {
                copyCurr->next = copyCurr->next->next;
                // Fix copied list next pointer
            } else {
                copyCurr->next = NULL;
            }

            curr = curr->next;
            // Move original pointer

            copyCurr = copyCurr->next;
            // Move copied pointer
        }

        // Return head of the deep copied list
        return copyHead;
    }
};
