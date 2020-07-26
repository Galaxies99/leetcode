class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = -1e9, mx2 = -1e9;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] > mx) {
                mx2 = mx;
                mx = nums[i];
            } else if (nums[i] > mx2) {
                mx2 = nums[i];
            }
        }
        return (mx - 1) * (mx2 - 1);
    }
};
