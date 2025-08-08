class Solution {
public:
    std::vector<std::vector<double>> dp;

    double helper(int n, int m) {
        if (n <= 0 && m <= 0)
            return 0.5;
        if (n <= 0)
            return 1.0;
        if (m <= 0)
            return 0.0;

        if (dp[n][m] != -1)
            return dp[n][m];

        // move 1 - 4
        double ans = (helper(n - 4, m) + helper(n - 3, m - 1) +
                      helper(n - 2, m - 2) + helper(n - 1, m - 3)) *
                     0.25;

        dp[n][m] = ans;
        return ans;
    }

    double soupServings(int n) {
        if (n > 4450)
            return 1.0;

        int units = (n + 24) / 25;
        dp.assign(units + 1, std::vector<double>(units + 1, -1.0));
        return helper(units, units);
    }
};