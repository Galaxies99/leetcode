class Solution {
public:
    int mySqrt(int x) {
        double cur = 4, pre;
        int ans;
        while(true) {
            pre = cur;
            cur = (cur + x / cur) / 2;
            if (fabs(cur - pre) < 1e-6) {
                ans = (int)cur;
                break;
            }
        }
        return ans;
    }
};
