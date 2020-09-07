class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++ i) {
            int j = i, mi = -1e9, sum = 0;
            while(s[j] == s[i]) ++ j;
            for (int k = i; k < j; ++ k)
                mi = max(mi, cost[k]), sum += cost[k];
            res += sum - mi;
            i = j - 1;
        }
        return res;
    }
};