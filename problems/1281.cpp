class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0, t;
        while(n) {
            t = n % 10;
            n = n / 10;
            prod *= t;
            sum += t;
        }
        return prod - sum;
    }
};
