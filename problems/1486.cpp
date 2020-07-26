class Solution {
public:
    int xorOperation(int n, int start) {
        int c = start, ans = 0;
        for (int i = 0; i < n; ++ i) {
            ans ^= c;
            c += 2;
        }
        return ans;
    }
};
