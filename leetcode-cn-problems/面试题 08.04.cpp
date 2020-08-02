class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int tot = (1 << nums.size());
        vector <vector <int> > res;
        for (int i = 0; i < tot; ++ i) {
            vector <int> t; t.clear();
            for (int j = 0; j < nums.size(); ++ j)
                if((i >> j) & 1) t.push_back(nums[j]);
            res.push_back(t);
        }
        return res;
    }
};
