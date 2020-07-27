class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        long long t = x;
        if (t < 0) {
            sign = -1;
            t = -t;
        }
        long long res = 0;
        while(t) {
            res = res * 10 + t % 10;
            t /= 10;
        }
        if (res < -2147483648ll || res > 2147483647) res = 0;
        return res * sign;
    }
};
