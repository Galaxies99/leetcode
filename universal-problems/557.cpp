class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] != ' ') {
                string t = "";
                int j = i;
                while(j < s.size() && s[j] != ' ') t += s[j ++];
                reverse(t.begin(), t.end());
                ans += t;
                i = j - 1;
            } else ans += ' ';
        }
        return ans;
    }
};
