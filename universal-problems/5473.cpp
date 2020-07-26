class Solution {
public:
    int minFlips(string target) {
        reverse(target.begin(), target.end());
        int cnt = 0;
        for (int i = 0; i < target.size(); ++ i) {
            if (target[i] == '1') {
                ++ cnt;
                int j = i;
                while(target[j] == '1') ++ j;
                i = j - 1;
            }
        }
        return cnt * 2 - 1 + (target[0] == '0');
    }
};
