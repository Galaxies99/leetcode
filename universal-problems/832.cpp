class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &line : A) 
            reverse(line.begin(), line.end());
        for (auto &line : A)
            for (auto &x : line)
                x = 1 - x;
        return A;
    }
};
