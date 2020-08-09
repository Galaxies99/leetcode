class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if (num1.size() < num2.size()) swap(num1, num2);
        string ans;
        int carry = 0;
        for (int i = 0; i < num1.size() && i < num2.size(); ++ i) {
            int t = num1[i] - '0' + num2[i] - '0' + carry; 
            carry = t / 10;
            ans += '0' + t % 10;
        }
        for (int i = num2.size(); i < num1.size(); ++ i) {
            int t = num1[i] - '0' + carry;
            carry = t / 10;
            ans += '0' + t % 10;
        }
        if (carry) ans += '0' + carry;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
