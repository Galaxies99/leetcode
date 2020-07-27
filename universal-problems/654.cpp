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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int pos = 0;
        for (int i = 0; i < nums.size(); ++ i) 
            if (nums[i] > nums[pos]) pos = i;
        TreeNode *p = new TreeNode(nums[pos]);
        vector <int> left, right;
        for (int i = 0; i < pos; ++ i)
            left.push_back(nums[i]);
        for (int i = pos + 1; i < nums.size(); ++ i)
            right.push_back(nums[i]);
        p -> left = constructMaximumBinaryTree(left);
        p -> right = constructMaximumBinaryTree(right);
        return p;
    }
};
