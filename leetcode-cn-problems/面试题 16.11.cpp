class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector <int> p; p.clear();
        if (k == 0) return p;
        for (int i = 0; i <= k; ++ i) 
            p.push_back(i * longer + (k - i) * shorter);
        p.erase(unique(p.begin(), p.end()), p.end());
        return p;
    }
};
