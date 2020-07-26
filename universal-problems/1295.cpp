class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0, cnt_t;
        for (auto x : nums) {
            cnt_t = 0;
            while(x) x /= 10, ++ cnt_t;
            cnt += (~ cnt_t & 1);
        }
        return cnt;
    }
};
