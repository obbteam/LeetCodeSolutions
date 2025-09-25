class Solution {
public:
    int minimumTotal(vector<vector<int>> triangle) {
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            int m = (int)triangle[i].size();
            for (int j = 0; j < m; ++j) {
                if (i > 0 && j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if (i > 0 && j == m - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else if (i > 0 && j > 0) {
                    triangle[i][j] +=
                        min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }

                dp[i] = min(dp[i], triangle[i][j]);
            }
        }

        return dp.back();
    }
};