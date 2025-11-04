class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int far = 0, curMax = 0, jumps = 0; 

        for (int i = 0; i < n - 1; ++i) {
            far = max(nums[i] + i, far);

            if (i == curMax) {
                jumps++;
                curMax = far;
                if (i == n - 2) return jumps;
            }
        }
        return jumps;
    }
};