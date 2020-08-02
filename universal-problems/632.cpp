class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector <int> all;
        for (auto lst: nums)
            for (auto num: lst) all.push_back(num);
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        vector <int> ptr;
        int ansl = all[0], ansr = -1e6;
        for (auto lst: nums) {
            ptr.push_back(0);
            ansr = max(ansr, lst[0]);
        }
        bool end = false;
        for (int i = 1; i < all.size(); ++ i) {
            int curl = all[i], curr = -1e6;
            for (int j = 0; j < nums.size(); ++ j) {
                while (ptr[j] < nums[j].size() && nums[j][ptr[j]] < all[i]) ++ ptr[j];
                if (ptr[j] == nums[j].size()) {
                    end = true;
                    break;
                }
                curr = max(curr, nums[j][ptr[j]]);
            }
            if (end) break;
            if (curr - curl < ansr - ansl) {
                ansl = curl;
                ansr = curr;
            }
        }
        vector <int> ans;
        ans.push_back(ansl);
        ans.push_back(ansr);
        return ans;
    }
};
