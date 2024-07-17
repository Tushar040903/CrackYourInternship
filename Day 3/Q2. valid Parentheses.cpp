bool isValid(string s) {
        stack<char> st;
        int index = 0;
        while(index < s.length()) {
            if(s[index] == '(' || s[index] == '[' || s[index] == '{') {
                st.push(s[index]);
            }
            else if(!st.empty() && s[index] == ')' && st.top() == '(') {
                st.pop();
            }
            else if(!st.empty() && s[index] == ']' && st.top() == '[') {
                st.pop();
            }
            else if(!st.empty() && s[index] == '}' && st.top() == '{') {
                st.pop();
            }
            else return false;

            index++;
        }

        if(st.size() > 0) return false;

        return true;
    }