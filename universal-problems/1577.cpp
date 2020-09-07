class Solution {
public:
    map <long long, int> mp1, mp2;
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        for (auto x : nums1) mp1[1ll * x * x] ++;
        for (auto x : nums2) mp2[1ll * x * x] ++;
        int ans = 0;
        for (int i = 0; i < nums1.size(); ++ i)
            for (int j = i + 1; j < nums1.size(); ++ j)
                ans += mp2[1ll * nums1[i] * nums1[j]];
        for (int i = 0; i < nums2.size(); ++ i)
            for (int j = i + 1; j < nums2.size(); ++ j)
                ans += mp1[1ll * nums2[i] * nums2[j]];
        return ans;
    }
};