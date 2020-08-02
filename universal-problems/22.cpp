class Solution {
public:
    vector<string> res;
    void dfs(int step, string cur, int curleft, int n) {
        if (step == n + n) {
            res.push_back(cur);
            return ;
        }
        if (curleft + 1 <= n)
            dfs(step + 1, cur + "(", curleft + 1, n);
        if (step - curleft < curleft)
            dfs(step + 1, cur + ")", curleft, n);
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        dfs(0, "", 0, n);
        return res;
    }
};
