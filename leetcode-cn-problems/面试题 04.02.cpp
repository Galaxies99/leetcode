/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int n = nums.size();
        TreeNode *p = new TreeNode(nums[n / 2]);
        vector<int> l, r;
        for (int i = 0; i < n; ++ i)
            if (i < n / 2) l.push_back(nums[i]);
            else if (i > n / 2) r.push_back(nums[i]);
        p -> left = sortedArrayToBST(l);
        p -> right = sortedArrayToBST(r);
        return p;
    }
};
