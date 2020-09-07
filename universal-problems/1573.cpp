const int mod = 1e9 + 7;
class Solution {
public:
    int numWays(string s) {
        int n = s.size();
        vector <int> p;
        p.resize(n);
        p[0] = s[0] - '0';
        for (int i = 1; i < n; ++ i)
            p[i] = p[i - 1] + (s[i] - '0');
        int avg = p[n - 1] / 3;
        if (p[n - 1] % 3 != 0) return 0;
        if (avg == 0) {
            return 1ll * (n - 1) * (n - 2) / 2 % mod;
        }
        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < n; ++ i) 
            if (p[i] == avg && pos1 == -1)
                pos1 = i;
            else if (p[i] == avg * 2 && pos2 == -1)
                pos2 = i;
        int nx = pos1 + 1;
        while (nx < n && p[nx] == p[pos1]) ++ nx;
        // i + 1, nx - 1
        int t1 = nx - pos1;
        nx = pos2 + 1;
        while (nx < n && p[nx] == p[pos2]) ++ nx;
        int t2 = nx - pos2;
        return 1ll * t1 * t2 % mod;
    }
};
