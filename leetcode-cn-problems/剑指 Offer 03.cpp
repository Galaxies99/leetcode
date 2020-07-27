class Solution {
public:
    map <int, bool> mp;
    int findRepeatNumber(vector<int>& nums) {
        for (auto x : nums) {
            if (mp[x]) return x;
            mp[x] = 1;
        }
        return -1;
    }
};
