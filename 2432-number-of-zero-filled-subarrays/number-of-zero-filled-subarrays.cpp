class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long prevZeros = 0;
        long long total = 0;
        for (int num : nums) {
            if (num == 0) {
                total += prevZeros + 1;
                prevZeros++;
            } else
                prevZeros = 0;
        }
        return total;
    }
};