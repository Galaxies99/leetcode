class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector < vector <int> > f;
        f.resize(m);
        for (auto &line : f) line.resize(m);
        for (int i = 0; i < m; ++ i) f[i][i] = 0;
        for (int i = 0; i + 1 < m; ++ i) f[i][i + 1] = 0;
        for (int len = 3; len <= m; ++ len) {
            for (int i = 0; i + len - 1 < m; ++ i) {
                int j = i + len - 1;
                f[i][j] = 1e9;
                for (int k = i + 1; k < j; ++ k)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                if (f[i][j] != (int)1e9) f[i][j] += cuts[j] - cuts[i];
            }
        }
        return f[0][m - 1];
    }
};