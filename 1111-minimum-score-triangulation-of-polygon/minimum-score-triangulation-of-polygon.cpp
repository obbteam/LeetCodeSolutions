class Solution {
public:
    int helper(int i, int j, int res, vector<int>& values,
               vector<vector<int>>& dp) {
        if (j == 0) j = values.size() - 1;

        if (dp[i][j] != 0)
            return dp[i][j];
        for (int k = i + 1; k < j; ++k) {
            res = min(res == 0 ? INT_MAX : res,
                      helper(i, k, 0, values, dp) +
                      values[i] * values[j] * values[k] +
                      helper(k, j, 0, values, dp));
        }
        dp[i][j] = res;
        return res;
    }

    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(), vector(values.size(), 0));

        return helper(0, 0, 0, values, dp);
    }
};