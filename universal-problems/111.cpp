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
    int mi;
    void dfs(TreeNode *root, int dep) {
        if (root == nullptr) return ;
        if (root -> left == nullptr && root -> right == nullptr) mi = min(mi, dep);
        dfs(root -> left, dep + 1);
        dfs(root -> right, dep + 1);
    }
    int minDepth(TreeNode* root) {
        mi = 1e9;
        dfs(root, 1);
        if (mi == 1e9) mi = 0;
        return mi;     
    }
};
