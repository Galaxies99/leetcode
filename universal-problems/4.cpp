class Solution {
public:

    int findKth(vector <int> &nums1, vector <int> &nums2, int K) {
        int i = 0, j = 0;
        while (true) {
            if (i == nums1.size()) return nums2[j + K - 1];
            if (j == nums2.size()) return nums1[i + K - 1];
            if (K == 1) return min(nums1[i], nums2[j]);
            int mid = K >> 1;
            int new_i = min(i + mid, (int) nums1.size()) - 1, new_j = min(j + mid, (int) nums2.size()) - 1;
            if (nums1[new_i] <= nums2[new_j]) {
                K -= (new_i - i + 1);
                i = new_i + 1;
            } else {
                K -= (new_j - j + 1);
                j = new_j + 1;
            }
        }
        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        if (n & 1) return findKth(nums1, nums2, n / 2 + 1);
        else return (findKth(nums1, nums2, n / 2) + findKth(nums1, nums2, n / 2 + 1)) / 2.0; 
    }
};
