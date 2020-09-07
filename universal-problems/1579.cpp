class Solution {
public:
    inline int getf(vector <int> &fa, int x) {
        return fa[x] == x ? x : fa[x] = getf(fa, fa[x]);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector <int> fa1, fa2;
        fa1.resize(n + 1); fa2.resize(n + 1);
        for (int i = 1; i <= n; ++ i) fa1[i] = i, fa2[i] = i;
        int useless = 0;
        for (auto e : edges) {
            if (e[0] == 3) {
                int fu = getf(fa1, e[1]), fv = getf(fa1, e[2]);
                int fuu = getf(fa2, e[1]), fvv = getf(fa2, e[2]);
                if (fu == fv) {
                    useless ++;
                } else {
                    fa1[fu] = fv;
                    fa2[fuu] = fvv;
                }
            }
        }
        for (auto e : edges) {
            if (e[0] == 1) {
                int fu = getf(fa1, e[1]), fv = getf(fa1, e[2]);
                if (fu == fv) {
                    useless ++;
                } else {
                    fa1[fu] = fv;
                }
            }
        }
        for (auto e : edges) {
            if (e[0] == 2) {
                int fu = getf(fa2, e[1]), fv = getf(fa2, e[2]);
                if (fu == fv) {
                    useless ++;
                } else {
                    fa2[fu] = fv;
                }
            }
        }
        int ff = getf(fa1, 1);
        for (int i = 1; i <= n; ++ i) if (getf(fa1, i) != ff) return -1;
        ff = getf(fa2, 1);
        for (int i = 1; i <= n; ++ i) if (getf(fa2, i) != ff) return -1;
        return useless;
    }
};