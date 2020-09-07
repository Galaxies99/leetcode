class Solution {
public:
    string getNext(string s) {
        string ret = "";
        for (int i = 0; i < s.size(); ++ i) {
            int j = i;
            while(j < s.size() && s[i] == s[j]) ++ j;
            ret += char(j - i + '0');
            ret += s[i];
            i = j - 1;
        }
        return ret;
    }
    string countAndSay(int n) {
        string res = "1";
        -- n;
        while(n --) res = getNext(res);
        return res;
    }
};