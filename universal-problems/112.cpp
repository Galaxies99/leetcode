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
    bool dfs(TreeNode *root, int cur, int sum) {
        if (root -> left == nullptr && root -> right == nullptr) {
            if (cur == sum) return true;
            else return false;
        }
        bool ans = 0;
        if (root -> left) ans |= dfs(root -> left, cur + root -> left -> val, sum);
        if (root -> right) ans |= dfs(root -> right, cur + root -> right -> val, sum);
        return ans;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        return dfs(root, root -> val, sum);    
    }
};
