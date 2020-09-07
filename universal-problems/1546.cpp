class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int lst = -1, n = nums.size(), ans = 0;
        vector <int> pre;
        map <int, int> mp;
        pre.resize(n);
        pre[0] = nums[0];
        mp[0] = -1;
        for (int i = 1; i < n; ++ i) pre[i] = pre[i - 1] + nums[i];
        for (int i = 0; i < n; ++ i) {
            if (mp.count(- target + pre[i])) {
                if (mp[- target + pre[i]] >= lst) {
                    ++ ans;
                    lst = i;
                } 
            }
            mp[pre[i]] = i;
        }
        return ans;
    }
};