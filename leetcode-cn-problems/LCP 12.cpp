class Solution {
public:
    bool chk(vector<int>& time, int m, int tm) {
        int cur = 0, cur_mx = 0, days = 1;
        for (auto t: time) {
            int nx = cur + t - max(cur_mx, t);
            if (nx > tm) {
                ++ days;
                cur = 0;
                cur_mx = 0;
            }
            cur += t;
            cur_mx = max(cur_mx, t);
        }
        return days <= m;
    }
    int minTime(vector<int>& time, int m) {
        int l = 0, r = 0, mid, ans;
        for (auto t: time) r += t;
        while(1) {
            if (r - l <= 3) {
                for (int i = l; i <= r; ++ i)
                    if (chk(time, m, i)) {
                        ans = i;
                        break;
                    }
                break;
            }
            int mid = l + r >> 1;
            if(chk(time, m, mid)) r = mid;
            else l = mid;
        }
        return ans;
    }
};
