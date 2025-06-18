class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        int leftSum = 0;
        for (int k = 0; k < nums.size(); ++k) {
            if (leftSum == sum - leftSum - nums[k])
                return k;

            leftSum += nums[k];
        }

        return -1;
    }
};