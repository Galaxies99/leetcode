class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector <int> rec; rec.resize(grid.size());
        for (int i = 0; i < grid.size(); ++ i)
            for (int j = grid[i].size() - 1; ~j; -- j)
                if (grid[i][j] == 0) rec[i] ++;
                else break;
        int ans = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            if (rec[i] < grid.size() - i - 1) {
                int res = -1;
                for (int j = i + 1; j < grid.size(); ++ j) {
                    if (rec[j] >= grid.size() - i - 1) {
                        res = j;
                        break;
                    }
                }
                if (res == -1) return -1;
                for (int k = res; k >= i + 1; -- k)
                    swap(grid[k], grid[k - 1]), swap(rec[k], rec[k - 1]);
                ans += (res - i);
            }
        }
        return ans;
    }
};
