class Solution {
public:
    bool judgeSquareSum(int c) {
        int limit = sqrt(c) + 1, j = limit;
        for (int i = 0; i <= limit; ++ i) {
            while (i <= j && 1ll * i * i + 1ll * j * j > c) -- j;
            if (1ll * i * i + 1ll * j * j == c) return true;
        }
        return false;
    }
};
