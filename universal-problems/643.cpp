class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0, mx;
        for (int i = 0; i < k; ++ i)
            sum += nums[i];
        mx = sum;
        for (int i = k; i < nums.size(); ++ i) {
            sum = sum + nums[i] - nums[i - k];
            mx = max(mx, sum);
        }
        return mx / k;
    }
};
