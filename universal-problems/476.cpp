class Solution {
public:
    int findComplement(int num) {
        vector <int> w;
        while(num) {
            w.push_back(num & 1);
            num >>= 1;
        }
        for (auto &x : w) x = !x;
        reverse(w.begin(), w.end());
        int ret = 0;
        for (auto x : w) ret = (ret << 1) + x;
        return ret;
    }
};
