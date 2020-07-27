class Solution {
public:
    static bool cmp(int x, int y) {
        return __builtin_popcount(x) < __builtin_popcount(y) || (__builtin_popcount(x) == __builtin_popcount(y) && x < y);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
