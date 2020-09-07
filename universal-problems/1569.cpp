const int mod = 1e9 + 7;
class Solution {
public:
    vector <int> t1, t2;
    int pwr(int x, int y) {
        int ans = 1;
        while(y) {
            if(y & 1) ans = 1ll * ans * x % mod;
            x = 1ll * x * x % mod;
            y >>= 1;
        }
        return ans;
    }
    vector <int> fac, inv;
    inline int C(int n, int m) {
        if (n < m || m < 0 || n < 0) return 0;
        return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
    int solve(int l, int r, vector <int>& nums) {
        if (l >= r) return 1;
        int pivot = nums[l];
        t1.clear(); t2.clear();
        for (int i = l + 1; i <= r; ++ i) {
            if (nums[i] < pivot) t1.push_back(nums[i]);
            if (nums[i] > pivot) t2.push_back(nums[i]);
        }
        int k = l + 1;
        for (int i = 0; i < t1.size(); ++ i)
            nums[k ++] = t1[i];
        int mid = k - 1;
        for (int i = 0; i < t2.size(); ++ i)
            nums[k ++] = t2[i];
        int ans = 1ll * solve(l + 1, mid, nums) * solve(mid + 1, r, nums) % mod;
        int lb = mid - l, rb = r - mid;
        return 1ll * ans * C(max(lb, rb) + min(lb, rb), min(lb, rb)) % mod;
    }
    int numOfWays(vector<int>& nums) {
        fac.resize(nums.size() + 5);
        inv.resize(nums.size() + 5);
        fac[0] = 1;
        for (int i = 1; i < fac.size(); ++ i) fac[i] = 1ll * fac[i - 1] * i % mod;
        for (int i = 0; i < fac.size(); ++ i) inv[i] = pwr(fac[i], mod - 2);
        int ans = solve(0, nums.size() - 1, nums) - 1;
        ans %= mod;
        if (ans < 0) ans += mod;
        return ans;
    }
};