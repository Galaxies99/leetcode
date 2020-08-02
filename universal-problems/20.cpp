class Solution {
public:
    stack <char> st;
    bool isValid(string s) {
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty()) return false;
                if (c == ')' && st.top() != '(') return false;
                if (c == ']' && st.top() != '[') return false;
                if (c == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
