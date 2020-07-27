class Solution {
public:
    int fib(int N) {
        vector <int> f;
        f.push_back(0), f.push_back(1);
        for (int i = 2; i <= N; ++ i) 
            f.push_back(f[i - 1] + f[i - 2]);
        return f[N];
    }
};
