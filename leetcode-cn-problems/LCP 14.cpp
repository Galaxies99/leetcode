class Solution {
public:
    vector <int> isnp; 
    vector <int> pr;
    vector <int> factor(int x) {
        vector <int> res;
        if (isnp[x] <= 0) {
            res.push_back(x);
            return res;
        }
        for (int i = 0; i < pr.size() && pr[i] < x; ++ i) {
            if (x % pr[i] == 0) {
                res.push_back(pr[i]);
                while (x % pr[i] == 0) x /= pr[i];
                if (isnp[x] <= 0) {
                    res.push_back(x);
                    return res;
                }
                if (x == 1) return res;
            }
        }
        if (x != 1) res.push_back(x);
        return res;
    }
    int splitArray(vector<int>& nums) {
        isnp.clear();
        pr.clear();
        isnp.resize(1e6 + 1);
        vector <int> f; 
        vector <int> g;
        f.resize(nums.size());
        for (int i = 2; i <= 1e6; ++ i)
            if (isnp[i] <= 0) {
                isnp[i] = - pr.size();
                pr.push_back(i);
                for (int j = i + i; j <= 1e6; j += i)
                    isnp[j] = true;
            }
        g.resize(pr.size());
        for (auto &x : g) x = 2e9;
        f[0] = 1;
        vector <int> t = factor(nums[0]);
        for (auto fact : t) g[-isnp[fact]] = min(g[-isnp[fact]], 0);
        for (int i = 1; i < nums.size(); ++ i) {
            t = factor(nums[i]);
            f[i] = f[i - 1] + 1;
            for (auto fact : t) 
                f[i] = min(f[i], g[-isnp[fact]] + 1);
            for (auto fact : t)
                g[-isnp[fact]] = min(g[-isnp[fact]], f[i - 1]);
        }
        return f[nums.size() - 1];
    }
};
