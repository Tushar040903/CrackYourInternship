ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = l1->val;
        int num2 = l2->val;
        int carry = 0;

        ListNode* ans = new ListNode((num1+num2)%10);
        if(num1+num2 >= 10) carry = 1;
        else carry = 0;
        ListNode* temp = ans;

        ListNode* temp1 = l1->next;
        ListNode* temp2 = l2->next;

        while(temp1 != NULL || temp2 != NULL) {
            if(temp1 != NULL && temp2 != NULL)  {
                num1 = temp1->val;
                num2 = temp2->val;
                int sum = num1+num2;
                if(carry == 1) sum = sum+1;

                ListNode* newNode = new ListNode(sum%10);
                if(sum >= 10) carry = 1;
                else carry = 0;

                temp->next = newNode;
                temp = newNode;

                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if(temp1 == NULL && temp2 != NULL) {
                num2 = temp2->val;
                int sum = num2;
                if(carry == 1) sum = sum+1;

                ListNode* newNode = new ListNode(sum%10);
                if(sum >= 10) carry = 1;
                else carry = 0;

                temp->next = newNode;
                temp = newNode;

                temp2 = temp2->next;
            }
            else if(temp1 != NULL && temp2 == NULL) {
                num1 = temp1->val;
                int sum = num1;
                if(carry == 1) sum = sum+1;

                ListNode* newNode = new ListNode(sum%10);
                if(sum >= 10) carry = 1;
                else carry = 0;

                temp->next = newNode;
                temp = newNode;

                temp1 = temp1->next;
            }
        }
        if(carry == 1) {
            ListNode* newNode = new ListNode(1);
            temp->next = newNode;
            temp = newNode;
        }

        return ans;
    }