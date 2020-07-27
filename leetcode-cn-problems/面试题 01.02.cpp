class Solution {
public:
    map <char, int> mp;
    bool CheckPermutation(string s1, string s2) {
        for (auto c : s1) mp[c] ++;
        for (auto c : s2) mp[c] --;
        for (auto i = mp.begin(); i != mp.end(); ++ i)
            if (i -> second) return false;
        return true;
    }
};
