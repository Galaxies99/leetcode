class CQueue {
public:
    stack <int> st[2];
    
    CQueue() {
        while(!st[0].empty()) st[0].pop();
        while(!st[1].empty()) st[1].pop();
    }
    
    void appendTail(int value) {
        st[0].push(value);
    }
    
    int deleteHead() {
        if(st[0].empty() && st[1].empty()) return -1;
        if(st[1].empty()) {
            while(!st[0].empty()) {
                int tp = st[0].top(); st[0].pop();
                st[1].push(tp);
            }
        }
        int ret = st[1].top();
        st[1].pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
