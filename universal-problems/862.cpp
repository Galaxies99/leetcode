class Solution {
public:
    deque <int> q;
    int shortestSubarray(vector<int>& A, int K) {
        vector <int> sum; sum.resize(A.size() + 1);
        sum[0] = 0;
        for (int i = 0; i < A.size(); ++ i)
            sum[i + 1] = sum[i] + A[i];
        int ans = 1e9;
        for (int i = 0; i <= A.size(); ++ i) {
            while(! q.empty() && sum[i] < sum[q.back()]) q.pop_back();
            while(! q.empty() && sum[i] - sum[q.front()] >= K) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return ans == 1e9 ? -1 : ans;
    }
};
