class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        if (digits.size() == 0) {
            digits.resize(1);
            digits[0] = 1;
            return digits;
        }
        digits[0] ++;
        int carry = 0;
        if (digits[0] >= 10) {
            carry = 1;
            digits[0] -= 10;
        }
        for (int i = 1; i < digits.size(); ++ i) {
            if (!carry) break;
            digits[i] += carry;
            if (digits[i] >= 10) {
                carry = 1;
                digits[i] -= 10;
            } else carry = 0;
        }
        if (carry) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
