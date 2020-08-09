class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ans = "";
        int to = 1e9;
        for (auto str : strs) to = min(to, (int)str.size());
        for (int i = 0; i < to; ++ i) {
            char ch = strs[0][i];
            bool flag = true;
            for (auto str : strs)
                if (ch != str[i]) {
                    flag = false;
                    break;
                }
            if (flag == false) break;
            ans += ch;
        }
        return ans;
    }
};
