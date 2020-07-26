class Solution {
public:
    int compress(vector<char>& chars) {
        int n = 0, N = 0;
        for (int i = 0; i < chars.size(); ++ i) {
            int j = i;
            while(j < chars.size() && chars[i] == chars[j]) ++ j;
            if (j - i == 1) chars[N ++] = chars[i];
            if (j - i > 1) {
                chars[N ++] = chars[i];
                int t = j - i, tt = t, tn = 0;
                while(tt) {
                    ++ tn;
                    tt /= 10;
                }
                tn += N - 1;
                N = tn + 1;
                while(t) {
                    chars[tn] = t % 10 + '0';
                    t /= 10;
                    -- tn;
                }
            }
            i = j - 1;
        }
        chars.resize(N);
        return N;
    }
};
