class Solution {
public:
    string replaceSpace(string s) {
        string ans = "";
        for (auto x : s)
            if(x == ' ') ans += "\%20";
            else ans += x;
        return ans;
    }
};
