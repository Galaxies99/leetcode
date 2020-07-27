class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (auto lines : matrix)
            for (auto x : lines)
                if (target == x) return true;
        return false;
    }
};
