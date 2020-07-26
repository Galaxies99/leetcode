class Solution {
public:
    bool chk(vector<int>& nums, int m, long long res) {
        long long t = 0;
        int ret = 0;
        for (auto num : nums) {
            if (num > res) return false;
            if (t + num <= res) t = t + num;
            else {
                ret ++;
                t = num;
            }
        }
        if (t) ret ++;
        return ret <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0, mid, ans;
        for (auto num : nums) r += num;
        while(1) {
            if (r - l <= 3) {
                for (int i = l; i <= r; ++ i)
                    if(chk(nums, m, i)) {
                        ans = i;
                        break;
                    }
                break;
            }
            mid = (l + r) >> 1;
            if(chk(nums, m, mid)) r = mid;
            else l = mid;
        }
        return (int)ans;
    }
};
