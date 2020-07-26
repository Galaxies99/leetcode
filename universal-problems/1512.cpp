class Solution {
public:
    map <int, int> mp;
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums) {
            ans += mp[x];
            mp[x] ++;
        }
        return ans;
    }
};
