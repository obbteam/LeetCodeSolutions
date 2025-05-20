class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto dp = cost;
        for (int i = cost.size() - 1 - 2; i >=0; --i) {
            dp[i] = dp[i] + std::min(dp[i+1], dp[i+2]);
        }

        return std::min(dp[0], dp[1]);
    }
};