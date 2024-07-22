ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL) {
            size++;
            temp = temp->next;
        }
        if(size == 1) {
            return NULL;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        int x = size-n+1;
        if(x == 1) {
            head = head->next;
            return head;
        }
        while(x!=1) {
            prev = curr;
            curr = curr->next;
            x--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        return head;
    }