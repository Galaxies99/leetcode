class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector <int> res;
        for (auto x : A) if (~ x & 1) res.push_back(x);
        for (auto x : A) if (x & 1) res.push_back(x);
        return res;
    }
};
