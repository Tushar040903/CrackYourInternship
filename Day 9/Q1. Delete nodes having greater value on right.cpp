Node *compute(Node *head)
    {
        // your code goes here
        stack<int> st;
        Node* temp = head;
        while(temp != NULL) {
            st.push(temp->data);
            temp = temp->next;
        }
        int y = st.top();
        st.pop();
        Node *ans = new Node(y);
        ans->next = NULL;
        int max = y;
        while(!st.empty()) {
            int x = st.top();
            st.pop();
            if(x >= max) {
                Node* newNode = new Node(x);
                max = x;
                newNode->next = ans;
                ans = newNode;
            }
        }
        
        return ans;
    }