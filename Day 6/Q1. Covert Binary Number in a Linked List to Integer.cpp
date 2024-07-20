// My solution 
int getDecimalValue(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp!=NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size()-1;
        int ans = 0;
        int i = 0;

        while(i < v.size()) {
            ans = ans + v[i]*pow(2,n);
            i++;
            n--;
        }

        return ans;
    }

    //Optimized solution
    int getDecimalValue(ListNode* head) {
        int ans = 0;

        ListNode* temp = head;

        while(temp!=NULL) {
            ans = (ans << 1) | temp->val;
            temp = temp->next;
        }

        return ans;
    }
