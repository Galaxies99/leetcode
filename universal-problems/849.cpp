class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int mx = 0;
        for (int i = 0; i < seats.size(); ++ i) {
            if (seats[i] == 0) {
                int j = i;
                while(j < seats.size() && seats[j] == 0) ++ j;
                if(i == 0 || j == seats.size())  mx = max(mx, j - i);
                else mx = max(mx, (j - i + 1) >> 1);
                i = j - 1;
            }
        }
        return mx;
    }
};
