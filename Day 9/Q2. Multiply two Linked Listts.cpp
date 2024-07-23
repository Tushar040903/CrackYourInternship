long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num1 = 0;
        long long num2 = 0;
        
        Node* temp = first;
        while(temp!=NULL) {
            num1 = (num1*10)%(1000000007) + temp->data;
            temp = temp->next;
        }
        
        temp = second;
        while(temp!=NULL) {
            num2 = (num2*10)%(1000000007) + temp->data;
            temp = temp->next;
        }
        
        return (num1*num2)%(1000000007);
    }