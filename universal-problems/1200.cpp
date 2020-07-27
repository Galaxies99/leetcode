class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mi = arr[1] - arr[0];
        vector <vector <int> > ans;
        vector <int> t; t.resize(2);
        t[0] = arr[0], t[1] = arr[1];
        ans.push_back(t);
        for (int i = 1; i < arr.size() - 1; ++ i) {
            if (arr[i + 1] - arr[i] < mi) {
                mi = arr[i + 1] - arr[i];
                ans.clear();
                t[0] = arr[i], t[1] = arr[i + 1];
                ans.push_back(t);
            } else if (arr[i + 1] - arr[i] == mi) {
                t[0] = arr[i], t[1] = arr[i + 1];
                ans.push_back(t);
            }
        }
        return ans;
    }
};
