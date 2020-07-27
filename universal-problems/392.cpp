class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cur = 0;
        for (auto c : s) {
            while(cur < t.size() && c != t[cur]) ++ cur;
            if(cur == t.size()) return false;
            ++ cur;
        }
        return true;
    }
};
