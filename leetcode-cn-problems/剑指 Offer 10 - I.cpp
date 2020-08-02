class Solution {
public:
    int fib(int n) {
        int mod = 1e9 + 7;
        vector <int> f;
        f.push_back(0), f.push_back(1);
        for (int i = 2; i <= n; ++ i) 
            f.push_back((f[i - 1] + f[i - 2]) % mod);
        return f[n];
    }
};
