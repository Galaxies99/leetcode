class Solution {
public:
    map <int, int> mp;
    stack <int> st;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans; ans.resize(nums1.size());
        for (int i = 0; i < nums1.size(); ++ i) mp[nums1[i]] = i + 1;
        for (int i = nums2.size() - 1; ~i; -- i) {
            while (!st.empty() && st.top() < nums2[i]) st.pop();
            if (mp[nums2[i]]) {
                if (st.empty()) ans[mp[nums2[i]] - 1] = -1;
                else ans[mp[nums2[i]] - 1] = st.top();
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};
