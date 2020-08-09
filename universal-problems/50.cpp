class Solution {
public:
    double myPow(double x, int n) {
        int sign = 0;
        long long tn = n;
        if (n < 0) {
            tn = -tn;
            sign = 1;
        }
        double res = 1.0;
        while(tn) {
            if (tn & 1) res = res * x;
            x = x * x;
            tn >>= 1;
        }
        return sign ? 1.0 / res : res;
    }
};
