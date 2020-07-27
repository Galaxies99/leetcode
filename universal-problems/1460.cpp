class Solution {
public:
    map <int, int> mp;
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        for (auto x : arr) mp[x] ++;
        for (auto x : target) mp[x] --;
        for (map <int, int> :: iterator it = mp.begin(); it != mp.end(); ++ it)
            if (it -> second != 0) return false;
        return true;
    }
};
