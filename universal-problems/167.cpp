class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size() - 1;
        vector <int> res; res.resize(2);
        for (int i = 0; i < numbers.size(); ++ i) {
            while(j > i && numbers[i] + numbers[j] > target) -- j;
            if (j <= i) break;
            if (j > i && numbers[i] + numbers[j] == target) {
                res[0] = i + 1, res[1] = j + 1;
                return res;
            }
        }
        return res;
    }
};
