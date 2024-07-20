ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0); // Create a dummy node
        dummy->next = head; // Point dummy's next to head
        ListNode* prev = dummy; // Initialize prev to dummy
        ListNode* curr = head; // Initialize curr to head

        while (curr != NULL) {
            if (curr->val == val) {
                prev->next = curr->next; // Bypass the current node
            } else {
                prev = curr; // Move prev to curr
            }
            curr = curr->next; // Move curr to next node
        }

        ListNode* newHead = dummy->next; // Save the new head
        delete dummy; // Delete the dummy node
        return newHead; // Return the new head
    }