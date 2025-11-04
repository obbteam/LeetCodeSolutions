class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), idx = n - 1;
        if (n < 2) return true;

        vector<bool> dp(n);
        int newTarget = INT_MAX;
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = (idx - i <= nums[i]) || (newTarget - i <= nums[i]);
            if (dp[i]) newTarget = i;
        }
        return dp[0];
    }
};