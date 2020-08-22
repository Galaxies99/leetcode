class Solution {
public:
    bool chk(vector <int> &position, int m, int k) {
        int lst = -1, res = 0;
        for (int i = 0; i < position.size(); ++ i) {
            if (lst == -1) {
                lst = position[i];
                ++ res;
            } else {
                if (position[i] - lst >= k) {
                    lst = position[i];
                    ++ res;
                }
            }
        }
        return res >= m;            
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = 1e9, mid, ans;
        while(1) {
            if (r - l <= 3) {
                for (int i = r; i >= l; -- i)
                    if (chk(position, m, i)) {
                        ans = i;
                        break;
                    }
                break;
            }
            int mid = l + r >> 1;
            if (chk(position, m, mid)) l = mid;
            else r = mid;
        }
        return ans;
    }
};