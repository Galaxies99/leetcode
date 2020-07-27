vector<int> ind;
class Solution {
public:
    inline static bool cmp(int x, int y) {
        return ind[x] > ind[y] || (ind[x] == ind[y] && x < y);
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ind.resize(1001);
        for (int i = 0; i < ind.size(); ++ i)
            ind[i] = 0;
        for (int i = 0; i < arr2.size(); ++ i)
            ind[arr2[i]] = arr2.size() - i;
        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};
