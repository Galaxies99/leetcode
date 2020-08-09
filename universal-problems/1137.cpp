class Solution {
public:
    int tribonacci(int n) {
        vector <int> f;
        f.push_back(0);
        f.push_back(1);
        f.push_back(1);
        if (n <= 2) return f[n];
        for (int i = 3; i <= n; ++ i)
            f.push_back(f[i-1] + f[i-2] + f[i-3]);
        return f[n];
    }
};
