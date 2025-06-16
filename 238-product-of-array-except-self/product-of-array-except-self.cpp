class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int countZeros = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0)
                product *= nums[i];
            else
                countZeros++;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!countZeros)
                nums[i] = product / nums[i];
            else if(countZeros == 1) {
                if(nums[i] == 0) nums[i] = product;
                else nums[i] = 0;
            } else {
                nums[i] = 0;
            }
        }
        return nums;
    }
};