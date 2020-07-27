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
    queue <pair<TreeNode*, int>> que;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <vector <int>> ans;
        vector <int> t;
        int cur_depth = 0;
        que.push(make_pair(root, 0));
        while(!que.empty()) {
            TreeNode *top = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (top == nullptr) continue;
            if (depth == cur_depth) {
                t.push_back(top -> val);
            } else {
                cur_depth = depth;
                ans.push_back(t);
                t.clear();
                t.push_back(top -> val);
            }
            if (top -> left) que.push(make_pair(top -> left, depth + 1));
            if (top -> right) que.push(make_pair(top -> right, depth + 1));
        }
        if(t.size()) ans.push_back(t);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
