class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Step 1: Check whether we have at least k nodes
        ListNode* temp = head;
        int count = 0;

        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
            // Move forward and count nodes
        }

        // If nodes are less than k, do not reverse
        if (count < k) {
            return head;
        }

        // Step 2: Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;     // Store next node
            curr->next = prev;     // Reverse link
            prev = curr;          // Move prev forward
            curr = next;          // Move curr forward
            count++;
        }

        // Now:
        // prev = new head of reversed group
        // head = last node of reversed group (after reversal)
        // curr = first node of next group

        // Step 3: Recursively reverse remaining list
        head->next = reverseKGroup(curr, k);
        // Connect last node of this group with the next reversed group

        // Step 4: Return new head of this group
        return prev;
    }
};
