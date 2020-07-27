const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
class Solution {
public:
    int n, m;
    bool ok;
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>> &vis, string word, int step) {
        if(ok) return;
        if (board[x][y] != word[step]) return ;
        if (step == word.size() - 1) {
            ok = 1;
            return ;
        }
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++ i) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue ;
            if(vis[xx][yy]) continue;
            dfs(xx, yy, board, vis, word, step + 1);
        }
        vis[x][y] = 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis;
        n = board.size(); m = board[0].size();
        vis.resize(n);
        for (int i = 0; i < n; ++ i) {
            vis[i].resize(m);
            for (int j = 0; j < m; ++ j)
                vis[i][j] = 0;
        }
        ok = 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j) {
                dfs(i, j, board, vis, word, 0);
                if (ok) return true;
            }
        return false;
    }
};
