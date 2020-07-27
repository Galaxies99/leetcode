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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) return nullptr;
        if (original == target) return cloned;
        TreeNode *t = getTargetCopy(original -> left, cloned -> left, target);
        if (t != nullptr) return t;
        else return getTargetCopy(original -> right, cloned -> right, target);
    }
};
