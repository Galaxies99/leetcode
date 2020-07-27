class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, mi = 1e9;
        for (auto x : nums) sum += x, mi = min(mi, sum);
        return max(- mi + 1, 1);
    }
};
