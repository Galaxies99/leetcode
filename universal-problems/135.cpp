class Solution {
public:
    int candy(vector<int>& ratings) {
        vector <int> left_ascending, right_ascending;
        int n = ratings.size();
        left_ascending.resize(n);
        right_ascending.resize(n);
        for (int i = 0; i < n; ++ i) {
            left_ascending[i] = 1;
            right_ascending[i] = 1;
        }
        for (int i = 1; i < n; ++ i) {
            if (ratings[i - 1] < ratings[i])
                left_ascending[i] = left_ascending[i - 1] + 1;
        }
        for (int i = n - 2; ~i; -- i) {
            if (ratings[i + 1] < ratings[i])
                right_ascending[i] = right_ascending[i + 1] + 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++ i) 
            ans += max(left_ascending[i], right_ascending[i]);
        return ans;
    }
};
