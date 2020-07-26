class Solution {
public:
    map<int, int> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        for (int i = 0; i < nums.size(); ++ i)
            mp[nums[i]] = i;
        for (int i = 0; i < nums.size(); ++ i)
            if (mp.count(target-nums[i]) && mp[target-nums[i]] != i) {
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                if(ans[0] > ans[1]) swap(ans[0], ans[1]);
                return ans;
            }
        return ans;
    }
};
