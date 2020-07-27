class Solution {
public:
    map <int, bool> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res;
        for (auto x : nums) {
            if (mp[target - x]) {
                res.push_back(x);
                res.push_back(target - x);
                return res;        
            }
            mp[x] = 1;
        }
        return res;
    }
};
