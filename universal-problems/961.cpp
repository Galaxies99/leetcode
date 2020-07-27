class Solution {
public:
    map <int, int> mp;
    int repeatedNTimes(vector<int>& A) {
        for (auto x : A) mp[x] ++;
        for (auto it = mp.begin(); it != mp.end(); ++ it)
            if(it -> second == A.size() / 2) return it -> first;
        return 0;
    }
};
