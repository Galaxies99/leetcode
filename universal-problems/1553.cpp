class Solution {
public:
    map <int, int> mp;
    int dp(int n) {
        if (n == 0) return 0;
        if (mp.count(n)) return mp[n];
        int ans1 = dp(n / 2) + n % 2 + (n >= 2);
        int ans2 = dp(n / 3) + n % 3 + (n >= 3);
        mp[n] = min(ans1, ans2);
        return mp[n];
    }
    int minDays(int n) {
        return dp(n);
    }
};