class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        long long ans1 = 0, ans2 = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ans1 += nums1[i];
                ++ i;
            } else if (nums1[i] > nums2[j]) {
                ans2 += nums2[j];
                ++ j;
            } else {
                ans1 = max(ans1, ans2) + nums1[i];
                ans2 = ans1;
                ++ i, ++ j;
            }
        }
        while (i < nums1.size()) {
            ans1 += nums1[i];
            ++ i;
        }
        while (j < nums2.size()) {
            ans2 += nums2[j];
            ++ j;
        }
        return max(ans1, ans2) % (int (1e9 + 7));
    }
};
