class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int pos1 = 0, pos2 = n - 1, res = n - 1;
        while(pos1 + 1 < n && arr[pos1] <= arr[pos1 + 1]) pos1 ++;
        while(pos2 - 1 >= 0 && arr[pos2] >= arr[pos2 - 1]) pos2 --;
        if (pos1 == n - 1 || pos2 == 0) return 0;
        res = min(res, min(n - pos1 - 1, pos2));
        for (int i = 0; i <= pos1; ++ i) {
            while (pos2 < n && arr[i] > arr[pos2]) ++ pos2;
            if (pos2 == n) break;
            res = min(res, pos2 - i - 1);
        }
        // pos1 + 1, n - 1, pos2 - 1
        return res;
    }
};