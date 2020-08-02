class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector < vector <int> > count, ans;
        count.resize(groupSizes.size() + 1);
        for (int i = 0; i < groupSizes.size(); ++ i)
            count[groupSizes[i]].push_back(i);
        for (int i = 1; i <= groupSizes.size(); ++ i) {
            for (int j = 0; j < count[i].size(); j += i) {
                vector <int> t;
                for (int k = 0; k < i; ++ k) t.push_back(count[i][j + k]);
                ans.push_back(t);
            }
        }
        return ans;
    }
};
