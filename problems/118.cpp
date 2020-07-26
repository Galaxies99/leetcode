class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res; 
        res.resize(numRows);
        for (int i = 0; i < numRows; ++ i) {
            for (int j = 0; j <= i; ++ j) {
                if (j == 0 || j == i) res[i].push_back(1);
                else res[i].push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }
        }
        return res;
    }
};
