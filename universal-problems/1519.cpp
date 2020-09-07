class Solution {
public:
    void dfs(vector < vector <int> > &E, string &labels, int x, int fa, vector < vector <int> > &dp) {
        for (int i = 0; i < 26; ++ i) dp[i][x] = (labels[x] == i + 'a');
        for (auto &end : E[x]) {
            if (end == fa) continue;
            dfs(E, labels, end, x, dp);
            for (int i = 0; i < 26; ++ i)
                dp[i][x] += dp[i][end];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector < vector <int> > E;
        E.resize(n);
        for (auto &e : edges) E[e[0]].push_back(e[1]), E[e[1]].push_back(e[0]);
        vector < vector <int> > dp;
        dp.resize(26);
        for (auto &line: dp) line.resize(n);
        dfs(E, labels, 0, -1, dp);
        vector <int> ans;
        for (int i = 0; i < n; ++ i) ans.push_back(dp[labels[i] - 'a'][i]);
        return ans;
    }
};