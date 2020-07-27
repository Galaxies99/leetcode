class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector <int> rows, cols;
        rows.resize(grid.size());
        cols.resize(grid[0].size());
        for (auto &x : rows) x = 0;
        for (auto &x : cols) x = 0;
        for (int i = 0; i < grid.size(); ++ i) 
            for (int j = 0; j < grid[i].size(); ++ j) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        int ans = 0;
        for (int i = 0; i < grid.size(); ++ i) 
            for (int j = 0; j < grid[i].size(); ++ j) 
                ans += min(rows[i], cols[j]) - grid[i][j];
        return ans;
    }
};
