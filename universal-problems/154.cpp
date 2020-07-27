class Solution {
public:
    int findMin(vector<int>& nums) {
        bool flag = 1;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; ++ i) {
            if (nums[i] > nums[i + 1]) {
                flag = 0;
                ans = nums[i + 1];
            }
        }
        if (flag) ans = nums[0];
        return ans;
    }
};
