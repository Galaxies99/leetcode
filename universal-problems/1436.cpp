class Solution {
public:
    map <string, int> mp;
    string destCity(vector<vector<string>>& paths) {
        for (auto x : paths) {
            mp[x[0]] ++;
            mp[x[1]] --;
        }
        for (map <string, int> :: iterator it = mp.begin(); it != mp.end(); ++ it)
            if (it -> second == -1) return it -> first;
        return "";
    }
};
