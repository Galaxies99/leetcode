class Solution {
public:
    string toLowerCase(string str) {
        for (auto &x : str) if (isupper(x)) x = tolower(x);
        return str;
    }
};
