class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, res = 0;
        for (auto x: s) {
            if (x == 'R') ++ cnt;
            else -- cnt;
            if (cnt == 0) ++ res;
        }
        return res;
    }
};
