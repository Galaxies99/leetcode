class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = 0, times = 0;
        for (auto x : nums) {
            if (x != cur) {
                -- times;
                if (times < 0) {
                    cur = x;
                    times = 1;
                }
            } else ++ times;
        }
        times = 0;
        for (auto x : nums)
            times += (x == cur);
        return times > nums.size() / 2 ? cur : -1;
    }
};
