class RecentCounter {
public:
    queue <int> q;
    RecentCounter() {
        while(!q.empty()) q.pop();
    }
    
    int ping(int t) {
        while(!q.empty()) {
            int top = q.front();
            if (top < t - 3000) q.pop();
            else break;
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
