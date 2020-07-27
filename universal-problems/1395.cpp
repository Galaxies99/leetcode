class Solution {
public:
    struct BIT {
        int n;
        vector <int> c;
        # define lb(x) x & (-x)
        BIT(int _n = 0) {
            n = _n;
            c.resize(n + 1);
        }
        void init(int _n) {
            n = _n;
            c.resize(n + 1);
            for (auto &x : c) x = 0;
        }
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
    int numTeams(vector<int>& rating) {
        int ans = 0;
        vector <int> all(rating);
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        for (auto &x : rating)
            x = lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
        BIT T[2]; T[0].init(all.size()); T[1].init(all.size());
        int front = 0, back = 1;
        for (auto x : rating) T[back].add(x, 1);
        for (auto x : rating) {
            T[front].add(x, 1);
            T[back].add(x, -1);
            ans += T[front].sum(1, x - 1) * T[back].sum(x + 1, all.size());
            ans += T[front].sum(x + 1, all.size()) * T[back].sum(1, x - 1);
        }
        return ans;
    }
};
