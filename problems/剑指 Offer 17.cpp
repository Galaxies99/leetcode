class Solution {
public:
    vector<int> printNumbers(int n) {
        vector <int> ans;
        int end = pow(10, n);
        for (int i = 1; i < end; ++ i)
            ans.push_back(i);
        return ans;
    }
};
