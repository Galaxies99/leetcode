class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> ans;
        int mx = -1e9;
        for (auto x : candies)
            mx = max(mx, x);
        for (auto x : candies)
            ans.push_back(x + extraCandies >= mx);
        return ans;
    }
};
