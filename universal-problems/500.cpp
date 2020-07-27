class Solution {
public:
    map <char, int> mp;
    vector<string> findWords(vector<string>& words) {
        vector <string> res;
        mp['q'] = mp['w'] = mp['e'] = mp['r'] = mp['t'] = mp['y'] = mp['u'] = mp['i'] = mp['o'] = mp['p'] = 1;
        mp['a'] = mp['s'] = mp['d'] = mp['f'] = mp['g'] = mp['h'] = mp['j'] = mp['k'] = mp['l'] = 2;
        mp['z'] = mp['x'] = mp['c'] = mp['v'] = mp['b'] = mp['n'] = mp['m'] = 3;
        for (auto word : words) {
            if (word == "") {
                res.push_back(word);
                continue;
            }
            int t = mp[tolower(word[0])];
            bool ok = true;
            for (auto &c : word) 
                if (mp[tolower(c)] != t) {
                    ok = false;
                    break;
                }
            if (ok) res.push_back(word);
        }
        return res;
    }
};
