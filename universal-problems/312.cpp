class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector < vector <int> > dp;
        int n = nums.size();
        dp.resize(n + 2);
        for (auto &line : dp) line.resize(n + 2);
        nums.resize(n + 2);
        for (int i = n; i; -- i)
            nums[i] = nums[i - 1];
        nums[0] = nums[n + 1] = 1;
        for (int len = 1; len <= n; ++ len)
            for (int i = 1; i + len - 1 <= n; ++ i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++ k) 
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
                }
        return dp[1][n];
    }
};
