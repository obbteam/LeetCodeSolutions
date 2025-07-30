class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int numZeros = 0, maxOnes = 0;

        auto start = 0, end = 0;

        while (end < nums.size()) {
            if (nums[end] == 1) {
                end++;
            } else if (nums[end] == 0 && numZeros == 0) {
                numZeros++;
                end++;
            } else {
                numZeros -= nums[start] == 0 ? 1 : 0;
                start++;
            }

            maxOnes = std::max(maxOnes, end - start);
        }

        return maxOnes - 1;
    }
};