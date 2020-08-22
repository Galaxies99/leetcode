class Solution {
public:
    int minOperations(int n) {
        int sum = 0;
        for (int i = 0; i < n; ++ i) {
            int num = 2 * i + 1;
            sum += num;
        }
        sum = sum / n;
        int ans = 0;
        for (int i = 0; i < n; ++ i) {
            int num = 2 * i + 1;
            if (num < sum) ans += sum - num;
        }
        return ans;
    }
};