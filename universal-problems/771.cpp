class Solution {
public:
    map <char, bool> jewel;
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        for (auto x : J) jewel[x] = 1;
        for (auto x : S) ans += jewel[x];
        return ans;
    }
};
