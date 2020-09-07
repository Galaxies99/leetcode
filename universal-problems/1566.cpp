class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int i = 0; i < (int)arr.size() - m * k + 1; ++ i) {
            bool flag = true;
            for (int j = 1; j < k; ++ j) {
                for (int l = 0; l < m; ++ l)
                    if (arr[i + l] != arr[i + l + j * m]) {
                        flag = false;
                        break;
                    }
                if (flag == false) break;
            }
            if (flag == true) return true;
        }
        return false;
    }
};
