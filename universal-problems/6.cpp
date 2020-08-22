class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector <vector <char> > res;
        res.resize(numRows);
        int p = numRows + numRows - 2;
        for (int i = 0; i < s.size(); i += p) {
            for (int j = 0; i + j < s.size() && j < numRows; ++ j)
                res[j].push_back(s[i + j]);
            for (int j = numRows, k = numRows - 2; i + j < s.size() && j < p; ++ j, -- k)
                res[k].push_back(s[i + j]);
        }
        string ans = "";
        for (auto &x : res)
            for (auto &t : x) ans += t;
        return ans;
    }
};