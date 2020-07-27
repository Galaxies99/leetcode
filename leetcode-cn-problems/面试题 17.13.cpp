class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        if (sentence.size() == 0) return 0;
        int n = sentence.size();
        vector <int> f; f.resize(n);
        for (int i = 0; i < n; ++ i) {
            string word = "";
            if (i) f[i] = f[i - 1] + 1;
            else f[i] = 1;
            for (auto word : dictionary) 
                if (i + 1 >= word.size() && sentence.substr(i - word.size() + 1, word.size()) == word) {
                    if (i - word.size() + 1 == 0) f[i] = 0;
                    else f[i] = min(f[i - word.size()], f[i]);
                }
        }
        return f[n - 1];
    }
};
