class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector < vector <int> > a;
        a.resize(n);
        for (int i = 0; i < n; ++ i) a[i].resize(m);
        for (auto p : indices) {
            for (int j = 0; j < m; ++ j) a[p[0]][j] ++;
            for (int j = 0; j < n; ++ j) a[j][p[1]] ++;
        }
        int cnt = 0;
        for (auto line : a)
            for (auto x : line)
                cnt += (x & 1);
        return cnt;
    }
};
