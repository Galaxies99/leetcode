class Solution {
public:
    vector<string> permutation(string S) {
        string t; t.resize(S.size());
        vector <string> ans;
        vector <int> p; p.resize(S.size());
        for (int i = 0; i < p.size(); ++ i) p[i] = i + 1;
        do {
            for (int i = 0; i < p.size(); ++ i)
                t[i] = S[p[i] - 1];
            ans.push_back(t);
        } while(next_permutation(p.begin(), p.end()));
        return ans;
    }
};
