class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector <int> vec, vec_t;
        map <string, int> mp;
        int idx = 0;
        for (int i = 0; i < str.size(); ++ i) {
            if (isalpha(str[i])) {
                int j = i;
                string wd = "";
                while(j < str.size() && isalpha(str[j])) wd += str[j ++];
                if (mp[wd] == 0) mp[wd] = ++ idx;
                vec.push_back(mp[wd]);
                i = j - 1;
            }
        }
        map <char, int> mp_t;
        int idx_t = 0;
        for (auto c: pattern) {
            if(mp_t[c] == 0) mp_t[c] = ++ idx_t;
            vec_t.push_back(mp_t[c]);
        }
        if (vec.size() != vec_t.size()) return false;
        for (int i = 0; i < vec.size(); ++ i)
            if (vec[i] != vec_t[i]) return false;
        return true;
    }
};
