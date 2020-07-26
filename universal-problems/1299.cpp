class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector <int> ans; 
        ans.resize(arr.size());
        for (int i = arr.size() - 2; ~i; -- i)
            ans[i] = max(ans[i + 1], arr[i + 1]);
        ans[arr.size() - 1] = -1;
        return ans;
    }
};
