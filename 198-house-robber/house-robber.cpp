class Solution {
public:
    int rob(std::vector<int> &nums) {
    std::vector<int> dp(nums.size() + 2, 0);
    int result = 0;

    for (int i = 0; i < nums.size(); i++) {
        dp[i + 2] = std::max(dp[i] + nums[i], dp[i+1]);
        result = std::max(result, dp[i + 2]);
    }

    return result;
}
};