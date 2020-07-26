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
    int mx;
    void dfs(TreeNode *root, int dep) {
        if (root == nullptr) return ;
        mx = max(mx, dep);
        dfs(root -> left, dep + 1);
        dfs(root -> right, dep + 1);
    }
    int maxDepth(TreeNode* root) {
        mx = 0;
        dfs(root, 1);
        return mx;
    }
};
