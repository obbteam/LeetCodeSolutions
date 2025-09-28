class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i >= 2; --i) {
            for (int j = i - 1; j >= 1; --j) {
                for (int k = j - 1; k >= 0; --k) {
                    if (nums[i] < nums[j] + nums[k])
                        return nums[i] + nums[j] + nums[k];
                }
            }
        }
        return 0;
    }
};