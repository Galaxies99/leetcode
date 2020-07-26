class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> ans, p(nums);
        sort(p.begin(), p.end());
        for (int i = 0; i < nums.size(); ++ i)
            ans.push_back(lower_bound(p.begin(), p.end(), nums[i]) - p.begin());
        return ans;
    }
};
