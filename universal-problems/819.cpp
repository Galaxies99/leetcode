class Solution {
public:
    map <string, int> mp;
    
    void to_lower(string &s) {
        for (auto &c : s)
            if (isupper(c)) c = tolower(c);
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (auto &s : banned) to_lower(s);
        for (int i = 0; i < paragraph.size(); ++ i) {
            if (isalpha(paragraph[i])) {
                string word = "";
                int j = i;
                while(j < paragraph.size() && isalpha(paragraph[j])) word += paragraph[j ++];
                to_lower(word);
                mp[word] ++;
                i = j - 1;
            }
        }
        for (auto s : banned) mp[s] = 0;
        string ans = ""; int cnt = 0;
        for (map <string, int> :: iterator it = mp.begin(); it != mp.end(); ++ it) {
            if (it -> second > cnt) {
                cnt = it -> second;
                ans = it -> first;
            }
        }
        return ans;
    }
};
