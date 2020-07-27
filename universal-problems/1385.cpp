class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (auto x : arr1) {
            bool f = true;
            for (auto y : arr2)
                if (abs(x - y) <= d) {
                    f = false;
                    break;
                }
            ans += f;
        }
        return ans;
    }
};
