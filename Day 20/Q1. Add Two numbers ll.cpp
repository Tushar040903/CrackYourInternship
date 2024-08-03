ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        // Push all values of l1 to s1
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push all values of l2 to s2
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* result = nullptr;
        int carry = 0;

        // Add digits until both stacks are empty and no carry is left
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            // Calculate new carry and the digit to store in the node
            carry = sum / 10;
            sum = sum % 10;

            // Create a new node and insert it at the front of the result list
            ListNode* newNode = new ListNode(sum);
            newNode->next = result;
            result = newNode;
        }

        return result;
    }







    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    // Helper function to add two reversed linked lists
    ListNode* addTwoNumbersReversed(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* curr = dummyHead;
        int carry = 0;
        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return dummyHead->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse both linked lists
        ListNode* l1Reversed = reverse(l1);
        ListNode* l2Reversed = reverse(l2);

        // Add the reversed linked lists
        ListNode* resultReversed = addTwoNumbersReversed(l1Reversed, l2Reversed);

        // Reverse the result to get the final sum in the correct order
        return reverse(resultReversed);
    }