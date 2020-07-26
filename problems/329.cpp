class Solution {
public:
    vector < vector <int> > G;
    vector <int> deg, pos, dp;
    queue <int> que;
    int n, m, N;

    int id(int i, int j) {
        return i * m + j;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) return 0;
        m = matrix[0].size();
        N = n * m;
        G.resize(N);
        deg.resize(N);
        pos.resize(N);
        dp.resize(N);
        for (int i = 0; i < N; ++ i) deg[i] = 0, dp[i] = 1;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j) {
                if (i && matrix[i][j] < matrix[i - 1][j])
                    G[id(i, j)].push_back(id(i - 1, j));
                if (j && matrix[i][j] < matrix[i][j - 1])
                    G[id(i, j)].push_back(id(i, j - 1));
                if (i < n - 1 && matrix[i][j] < matrix[i + 1][j])
                    G[id(i, j)].push_back(id(i + 1, j));
                if (j < m - 1 && matrix[i][j] < matrix[i][j + 1])
                    G[id(i, j)].push_back(id(i, j + 1));
            }
        for (int i = 0; i < N; ++ i)
            for (int j = 0; j < G[i].size(); ++ j)
                deg[G[i][j]] ++;
        while(!que.empty()) que.pop();
        for (int i = 0; i < N; ++ i)
            if (deg[i] == 0) que.push(i);
        int idx = 0;
        while(!que.empty()) {
            int top = que.front(); que.pop();
            pos[idx ++] = top;
            for (int i = 0; i < G[top].size(); ++ i) {
                -- deg[G[top][i]];
                if (deg[G[top][i]] == 0)
                    que.push(G[top][i]);
            }
        }
        for (int i = 0; i < N; ++ i) {
            int x = pos[i];
            for (int j = 0; j < G[x].size(); ++ j) {
                int y = G[x][j];
                dp[y] = max(dp[x] + 1, dp[y]);
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++ i)
            ans = max(ans, dp[i]);
        return ans;
    } 
};
