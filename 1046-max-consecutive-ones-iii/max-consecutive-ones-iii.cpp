class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int start = 0, end = 0, numZeros = 0, windowSize = 0;
        while (end < nums.size()) {
            if (nums[end] == 1)
                end++;
            else if (nums[end] == 0 && numZeros < k) {
                numZeros++;
                end++;
            } else {
                numZeros -= nums[start] == 0 ? 1 : 0;
                start++;
            }
            windowSize = std::max(windowSize, end - start);
        }
        return windowSize;
    }
};