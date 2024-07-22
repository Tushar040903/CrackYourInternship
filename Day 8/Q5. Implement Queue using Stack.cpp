class MyQueue {
public:
    int size = 0;
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        this->size = 0;
    }
    
    void push(int x) {
        st1.push(x);
        size++;
    }
    
    int pop() {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int x = st2.top();
        st2.pop();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        size--;
        return x;
    }
    
    int peek() {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int x = st2.top();

        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return x;
    }
    
    bool empty() {
        if(size == 0) return true;
        return false;
    }
};