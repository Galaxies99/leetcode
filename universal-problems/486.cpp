class Solution {
public:
    int getsum(vector <int> &pre, int i, int j) {
        if (i == 0) return pre[j];
        else return pre[j] - pre[i - 1];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums) sum += x;
        vector <int> pre;
        vector < vector <int> > f, g;
        int n = nums.size();
        f.resize(n);
        g.resize(n);
        pre.resize(n);
        for (auto &line : f) line.resize(n);
        for (auto &line : g) line.resize(n);
        for (int i = 0; i < n; ++ i) f[i][i] = nums[i], g[i][i] = 0;
        for (int i = 0; i + 1 < n; ++ i) f[i][i + 1] = max(nums[i], nums[i + 1]), g[i][i + 1] = min(nums[i], nums[i + 1]);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++ i) pre[i] = pre[i - 1] + nums[i];
        for (int len = 3; len <= n; ++ len)
            for (int i = 0; i + len - 1 < n; ++ i) {
                int j = i + len - 1;
                f[i][j] = max(f[i][j], g[i + 1][j] + nums[i]);
                f[i][j] = max(f[i][j], g[i][j - 1] + nums[j]);
                g[i][j] = getsum(pre, i, j) - f[i][j];
            }
        return f[0][n - 1] >= g[0][n - 1];
    }
};