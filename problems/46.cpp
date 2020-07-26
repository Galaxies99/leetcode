class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector <int> p, t;
        vector <vector <int> > ans;
        for (int i = 0; i < n; ++ i)
            p.push_back(i);
        do {
            t.clear();
            for (int i = 0; i < n; ++ i)
                t.push_back(nums[p[i]]);
            ans.push_back(t);
        } while(next_permutation(p.begin(), p.end()));
        return ans;
    }
};
