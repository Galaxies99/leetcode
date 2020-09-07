class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < (int)nums.size(); ++ i) {
            if (nums[i] == 0) continue;
            
            int j = i;
            while (j < (int)nums.size() && nums[j] != 0) ++ j;
            int cnt = 0;
            for (int k = i; k < j; ++ k)
                cnt += (nums[k] < 0);
            
            if (cnt % 2 == 0) {
                ans = max(ans, j - i);
            } else {
                int l = -1, r = -1;
                for (int k = i; k < j; ++ k) {
                    if (nums[k] < 0) {
                        l = k;
                        break;
                    }
                }
                for (int k = j - 1; k >= i; -- k) {
                    if (nums[k] < 0) {
                        r = k;
                        break;
                    }
                }
                // left + 1, j; i, right
                ans = max(ans, j - l - 1);
                ans = max(ans, r - i);
            }
            i = j;
        }
        return ans;
    }
};