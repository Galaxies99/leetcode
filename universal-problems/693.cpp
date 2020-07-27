class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lst = n & 1;
        n >>= 1;
        while(n) {
            if ((n & 1) == lst) return false;
            lst = n & 1;
            n >>= 1;
        }
        return true;
    }
};
