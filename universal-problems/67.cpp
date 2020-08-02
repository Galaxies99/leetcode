class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c;
        int carry = 0;
        if (a.size() < b.size()) swap(a, b);
        for (int i = 0; i < a.size() && i < b.size(); ++ i) {
            int t = a[i] - '0' + b[i] - '0' + carry;
            c.push_back((t & 1) + '0');
            carry = (t >> 1);
        }
        for (int i = b.size(); i < a.size(); ++ i) {
            int t = a[i] - '0' + carry;
            c.push_back((t & 1) + '0');
            carry = (t >> 1);
        }
        if(carry) c.push_back('1');
        reverse(c.begin(), c.end());
        return c;
    }
};
