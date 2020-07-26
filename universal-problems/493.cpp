class Solution {
public:
    struct BIT {
        vector <int> c;
        int n;
        BIT(int _n) {
            n = _n;
            c.resize(n + 1);
            for (auto &x : c) x = 0;
        } 
        # define lb(x) (x & (-x))
        void add(int x, int d) {
            for (; x <= n; x += lb(x))
                c[x] += d;
        }
        int sum(int x) {
            int res = 0;
            for (; x; x -= lb(x))
                res += c[x];
            return res;
        }
        int sum(int x, int y) {
            if (x > y) return 0;
            return sum(y) - sum(x - 1);
        }
        # undef lb
    };

    int reversePairs(vector<int>& nums) {
        vector <long long> all;
        for (auto x : nums) all.push_back(x), all.push_back(2ll * x);
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        int n = all.size(), ans = 0;
        BIT T(n);
        for (auto x : nums) {
            int p1 = lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
            int p2 = lower_bound(all.begin(), all.end(), 2ll * x) - all.begin() + 1;
            ans += T.sum(p2 + 1, n);
            T.add(p1, 1);
        }
        return ans;
    }
};
