class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (auto line : grid)
            for (auto x : line)
                cnt += (x < 0);
        return cnt;
    }
};
