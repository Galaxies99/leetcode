const int mod = 1e9 + 7;
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector < vector <int> > f;
        f.resize(201);
        for (auto &line : f) line.resize(n + 1);
        f[0][start] = 1;
        for (int i = 1; i <= fuel; ++ i)
            for (int j = 0; j < n; ++ j) {
                for (int k = 0; k < n; ++ k) {
                    if (j == k) continue;
                    if (i >= abs(locations[j] - locations[k])) f[i][j] += f[i - abs(locations[j] - locations[k])][k];
                    if (f[i][j] >= mod) f[i][j] -= mod;
                }
            }
        int res = 0;
        for (int i = 0; i <= fuel; ++ i) {
            res += f[i][finish];
            if (res >= mod) res -= mod;
        }
        return res;
    }
};