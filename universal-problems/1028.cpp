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
    TreeNode* doit(string S, int depth) {
        if(S == "") return nullptr;
        string c = "";
        int pos1 = S.size(), pos2 = -1;
        for (int i = 0; i < S.size(); ++ i) {
            if (S[i] == '-') {
                int j = i;
                while(S[j] == '-') ++ j;
                if (j - i == depth) {
                    pos1 = i;
                    pos2 = j;
                    break;
                }
                i = j - 1;
            }
        }
        TreeNode *p = new TreeNode(stoi(S.substr(0, pos1)));
        if (pos1 == S.size()) return p;
        S = S.substr(pos2);
        pos1 = S.size(), pos2 = -1;
        for (int i = 0; i < S.size(); ++ i) {
            if (S[i] == '-') {
                int j = i;
                while(S[j] == '-') ++ j;
                if (j - i == depth) {
                    pos1 = i;
                    pos2 = j;
                    break;
                }
                i = j - 1;
            }
        }
        p -> left = doit(S.substr(0, pos1), depth + 1);
        if(pos1 != S.size()) p -> right = doit(S.substr(pos2), depth + 1);
        return p;
    }
    TreeNode* recoverFromPreorder(string S) {
        return doit(S, 1);
    }
};
