class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (auto & x : A) x = x * x;
        sort(A.begin(), A.end());
        return A;
    }
};
