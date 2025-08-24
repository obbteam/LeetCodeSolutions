class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int start = 0, end = 0, maxOnes = 0, numZeros = 0;

        while (end < nums.size()) {
            if (nums[end] == 1)
                end++;
            else if (nums[end] == 0 && numZeros == 0) {
                end++;
                numZeros++;
            } else {
                numZeros -= nums[start] == 0 ? 1 : 0;
                start++;
            }
            maxOnes = max(maxOnes, end - start - 1);
        }
        return maxOnes;
    }
};