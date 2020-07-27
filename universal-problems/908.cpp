class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mx = -1e9, mi = 1e9;
        for (auto x : A) mx = max(mx, x), mi = min(mi, x);
        return max(mx - mi - K - K, 0);
    }
};
