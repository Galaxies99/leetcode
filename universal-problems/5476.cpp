class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = 0;
        for (auto x : arr) mx = max(mx, x);
        if (k >= arr.size()) return mx;
        deque <int> res;
        for (auto x : arr) res.push_back(x);
        int K = 0;
        while (K < k) {
            if (res[0] > res[1]) {
                int t = res.front(); res.pop_front();
                int tt = res.front(); res.pop_front(); res.push_back(tt); res.push_front(t);
                ++ K;
            } else {
                int t = res.front(); res.pop_front();
                int tt = res.front(); res.pop_front(); res.push_back(t); res.push_front(tt);
                K = 1;
            }
        }
        return res[0];
    }
};
