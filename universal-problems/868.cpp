class Solution {
public:
    int binaryGap(int N) {
        vector <int> w;
        while(N) {
            w.push_back(N & 1);
            N >>= 1;
        }
        int ans = 0, lst = -1;
        for (int i = 0; i < w.size(); ++ i) 
            if (w[i]) {
                if (lst != -1) ans = max(ans, i - lst);
                lst = i;
            }
        return ans;
    }
};
