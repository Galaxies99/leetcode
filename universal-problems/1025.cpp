class Solution {
public:
    bool divisorGame(int N) {
        return (bool)(~ N & 1);
    }
};
