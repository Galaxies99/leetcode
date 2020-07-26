class Solution {
public:
    # define lb(x) (x & (-x))
    struct BIT {
        int N;
        vector <int> c;
        void init(int _N) {
            N = _N;
            c.resize(N + 1);
            for (int i = 1; i <= N; ++ i) c[i] = 0;
        }
        void add(int x, int d) {
            for (; x <= N; x += lb(x))
                c[x] += d;
        }
        int sum(int x) {
            int res = 0;
            for (; x; x -= lb(x))
                res += c[x];
            return res;
        }
    }T;
    # undef lb

    vector<int> countSmaller(vector<int>& nums) {
        vector <int> all(nums), ans;
        ans.resize(nums.size());
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        int N = all.size();
        T.init(N); 
        for (int i = nums.size() - 1; ~i; -- i) {
            int c = lower_bound(all.begin(), all.end(), nums[i]) - all.begin() + 1;
            ans[i] = T.sum(c - 1);
            T.add(c, 1);
        }
        return ans;
    }
};
