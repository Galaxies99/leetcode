class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector <int> f, g, h;
        f.resize(prices.size());
        g.resize(prices.size());
        h.resize(prices.size());
        for (int i = 0; i < prices.size(); ++ i) {
            if (i) f[i] = prices[i] + h[i - 1];
            else f[i] = 0;
            if (i) g[i] = max(g[i - 1], f[i]);
            else g[i] = f[i];
            if (i >= 2) h[i] = max(h[i - 1], g[i - 2] - prices[i]);
            else if (i == 1) h[i] = max(h[i - 1], - prices[i]);
            else h[i] = -prices[i];
        }
        return g[prices.size() - 1];
    }
};
