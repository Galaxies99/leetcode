class Solution {
public:
    int maximum69Number (int num) {
        vector <int> digit;
        while(num) {
            digit.push_back(num % 10);
            num /= 10;
        }
        reverse(digit.begin(), digit.end());
        for (auto &x : digit) {
            if (x == 6) {
                x = 9;
                break;
            }
        }
        int ans = 0;
        for (auto x : digit)
            ans = ans * 10 + x;
        return ans;
    }
};
