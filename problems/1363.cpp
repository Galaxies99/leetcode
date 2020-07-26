class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int sum = 0;
        int cnt[3] = {0, 0, 0};
        for (auto x : digits) {
            sum += x;
            cnt[x % 3] ++;
        }
        sum = sum % 3;
        if (sum == 1) {
            if (cnt[1]) {
                // delete one 1
                int t_min = 10;
                for (auto x : digits)
                    if (x % 3 == 1) t_min = min(t_min, x);
                digits.erase(find(digits.begin(), digits.end(), t_min));
            } else {
                // delete two 2s
                int t_min = 10;
                for (auto x : digits)
                    if (x % 3 == 2) t_min = min(t_min, x);
                digits.erase(find(digits.begin(), digits.end(), t_min));
                t_min = 10;
                for (auto x : digits)
                    if (x % 3 == 2) t_min = min(t_min, x);
                digits.erase(find(digits.begin(), digits.end(), t_min));                
            }
        } else if (sum == 2) {
            if (cnt[2]) {
                // delete one 2
                int t_min = 10;
                for (auto x : digits)
                    if (x % 3 == 2) t_min = min(t_min, x);
                digits.erase(find(digits.begin(), digits.end(), t_min));
            } else {
                // delete two 1s
                int t_min = 10;
                for (auto x : digits)
                    if (x % 3 == 1) t_min = min(t_min, x);
                digits.erase(find(digits.begin(), digits.end(), t_min));
                t_min = 10;
                for (auto x : digits)
                    if (x % 3 == 1) t_min = min(t_min, x);
                digits.erase(find(digits.begin(), digits.end(), t_min));                
            }
        }
        string ans = "";
        sort(digits.begin(), digits.end());
        reverse(digits.begin(), digits.end());
        for (auto x : digits)
            ans = ans + to_string(x);
        if (ans.size() > 0 && ans[0] == '0') ans = "0";
        return ans;
        return "";
    }
};
