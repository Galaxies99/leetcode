class Solution {
public:
    string longestPalindrome(string s) {
        string str = "$#";
        for (auto c : s) {
            str += c;
            str += "#";
        }
        vector <int> p; 
        p.resize(str.size());
        int mx = 0, id, res = -1, pos;
        for (int i = 1; i < str.size(); ++ i) {
            if (i < mx) p[i] = min(p[id + id - i], mx - i);
            else p[i] = 1;

            while (i + p[i] < str.size() && i - p[i] >= 0 && str[i + p[i]] == str[i - p[i]]) ++ p[i];

            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            
            if (p[i] >= res) {
                res = p[i];
                pos = i;
            }
        }

        string ans = "";
        if (str[pos] != '$' && str[pos] != '#') ans += str[pos];
        for (int i = 1; pos + i < str.size() && pos - i >= 0; ++ i) {
            if (str[pos + i] != str[pos - i]) break;
            if (str[pos + i] != '$' && str[pos + i] != '#') ans = str[pos - i] + ans + str[pos  + i];
        }
        return ans;
    }
};
