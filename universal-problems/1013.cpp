class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (auto x : A) sum += x;
        if (sum % 3) return false;
        sum /= 3;
        int parts = 0;
        int cur = 0;
        for (int i = 0; i < A.size(); ++ i) {
            cur = cur + A[i];
            if(cur == sum) {
                cur = 0;
                ++ parts;
            }
        }
        return parts >= 3;
    }
};
