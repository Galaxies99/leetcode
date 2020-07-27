class Solution {
public:
    map <char, int> mp;
    int lengthOfLongestSubstring(string s) {
        int ans = 0, j = 0;
        while(j < s.size() && mp[s[j]] == 0) mp[s[j ++]] ++;
        ans = j;
        for (int i = 0; i < s.size(); ++ i) {
            mp[s[i]] --;
            while(j < s.size() && mp[s[j]] == 0) mp[s[j ++]] ++;
            ans = max(ans, j - i - 1);
        }
        return ans;
    }
};
