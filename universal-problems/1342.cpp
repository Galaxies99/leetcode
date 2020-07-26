class Solution {
public:
    int numberOfSteps (int num) {
        return num == 0 ? 0 : 31 - __builtin_clz(num) + __builtin_popcount(num);
    }
};
