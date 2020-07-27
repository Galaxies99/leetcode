class Solution {
public:
    map <string, bool> mp;
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (auto word : words) {
            string encode = "";
            for (auto x : word) 
                encode = encode + code[x - 'a'];
            mp[encode] = true;
        }
        int ans = 0;
        for (map <string, bool> :: iterator it = mp.begin(); it != mp.end(); ++ it)
            if (it -> second) ++ ans;
        return ans;
    }
};
