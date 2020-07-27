class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        for (int i = 0; i < points.size(); ++ i)
            for (int j = i + 1; j < points.size(); ++ j)
                for (int k = j + 1; k < points.size(); ++ k) {
                    double a = sqrt((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));
                    double b = sqrt((points[i][0] - points[k][0]) * (points[i][0] - points[k][0]) + (points[i][1] - points[k][1]) * (points[i][1] - points[k][1]));
                    double c = sqrt((points[j][0] - points[k][0]) * (points[j][0] - points[k][0]) + (points[j][1] - points[k][1]) * (points[j][1] - points[k][1]));
                    double p = (a + b + c) / 2;
                    double S = sqrt(p * (p - a) * (p - b) * (p - c));
                    if (S > ans) ans = S;
                }
        return ans;
    }
};
