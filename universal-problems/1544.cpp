class Solution {
public:
    int check(string &s) {
        for (int i = 0; i + 1 < s.size(); ++ i) {
            if (isupper(s[i]) && islower(s[i + 1]) && s[i] - 'A' == s[i + 1] - 'a')
                return i;
            if (islower(s[i]) && isupper(s[i + 1]) && s[i] - 'a' == s[i + 1] - 'A')
                return i;
        }
        return -1;
    }
    string makeGood(string s) {
        int t;
        while((t = check(s)) != -1) {
            string ss;
            for (int i = 0; i < t; ++ i) ss += s[i];
            for (int i = t + 2; i < s.size(); ++ i) ss += s[i];
            s = ss;
        }
        return s;
    }
};