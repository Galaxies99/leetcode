class Solution {
public:
    stack <char> st;
    string removeOuterParentheses(string S) {
        string ans = "";
        for (auto c : S) {
            if (c == '(') {
                if (! st.empty()) ans = ans + c;
                st.push('(');
            } else {
                st.pop();
                if (! st.empty()) ans = ans + c;
            }
        }
        return ans;
    }
};
