class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> deg;   
        vector <vector <int> > E;
        E.resize(numCourses); deg.resize(numCourses);
        for (auto item : prerequisites) 
            E[item[0]].push_back(item[1]), deg[item[1]] ++;
        queue <int> q;
        for (int i = 0; i < numCourses; ++ i)
            if (deg[i] == 0) 
                q.push(i);
        int num = 0;
        while (!q.empty()) {
            int top = q.front(); q.pop();
            ++ num;
            for (auto to : E[top]) {
                deg[to] --;
                if (deg[to] == 0) q.push(to);
            }
        }
        return num == numCourses;
    }
};
