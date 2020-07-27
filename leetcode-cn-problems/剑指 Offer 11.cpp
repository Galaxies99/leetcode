class Solution {
public:
    int minArray(vector<int>& numbers) {
        bool flag = 1;
        int ans = 0;
        for (int i = 0; i < numbers.size() - 1; ++ i) {
            if (numbers[i] > numbers[i + 1]) {
                flag = 0;
                ans = numbers[i + 1];
            }
        }
        if (flag) ans = numbers[0];
        return ans;
    }
};
