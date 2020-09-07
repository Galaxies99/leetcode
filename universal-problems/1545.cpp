class Solution {
public:
    char findKthBit(int n, int k) {
        string s, t;
        if (n == 1) return '0';
        t = "0";
        for (int i = 2; i <= n; ++ i) {
            s = t + "1";
            for (auto &c : t) c = 1 - (c - '0') + '0';
            reverse(t.begin(), t.end());
            s += t;
            t = s;
        }
        return s[k - 1];
    }
};