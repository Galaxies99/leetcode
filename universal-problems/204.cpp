class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector <bool> isnp;
        isnp.resize(n);
        for (int i = 2; i < n; ++ i) {
            if (!isnp[i]) {
                cnt ++;
                for (int j = i + i; j < n; j += i)
                    isnp[j] = 1;
            }
        }
        return cnt;
    }
};
