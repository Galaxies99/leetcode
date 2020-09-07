class Solution {
public:
    map <char, int> mp;
    string modifyString(string s) {
        if (s.size() == 1) {
            if (s[0] == '?') s[0] = 'a';
            return s;
        }
        for (int i = 0; i < s.size(); ++ i)
            if (s[i] == '?') {
                if (i == 0) {
                    if (s[i + 1] != 'a') s[i] = 'a';
                    else s[i] = 'b';
                } else if (i == s.size() - 1) {
                    if (s[i - 1] != 'a') s[i] = 'a';
                    else s[i] = 'b';
                } else {
                    if (s[i - 1] != 'a' && s[i + 1] != 'a') s[i] = 'a';
                    else {
                        if (s[i - 1] == 'a') {
                            if (s[i + 1] != 'b') s[i] = 'b';
                            else s[i] = 'c';
                        } else {
                            if (s[i - 1] != 'b') s[i] = 'b';
                            else s[i] = 'c';
                        }
                    }
                }
            }
        return s;
    }
};