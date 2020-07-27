class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> res;
        res.resize(A[0].size());
        for (auto &x : res) x.resize(A.size());
        for (int i = 0; i < res.size(); ++ i)
            for (int j = 0; j < res[i].size(); ++j)
                res[i][j] = A[j][i];
        return res;
    }
};
