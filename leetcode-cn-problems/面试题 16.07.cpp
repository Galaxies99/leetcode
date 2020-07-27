class Solution {
public:
    int maximum(int a, int b) {
        return (1ll * a + b + abs(1ll * a - b)) / 2;
    }
};
