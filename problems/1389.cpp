class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector <int> target;
        for (int i = 0; i < nums.size(); ++ i) {
            target.push_back(0);
            for (int j = target.size() - 2; j >= index[i]; -- j)
                target[j + 1] = target[j];
            target[index[i]] = nums[i];
        }
        return target;
    }
};
