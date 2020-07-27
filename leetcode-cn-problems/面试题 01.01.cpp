class Solution {
public:
    bool isUnique(string astr) {
        int n = astr.size();
        sort(astr.begin(), astr.end());
        astr.erase(unique(astr.begin(), astr.end()), astr.end());
        return astr.size() == n;
    }
};
