class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        std::unordered_set<int> uniqueNums;
        for (int j = 1; j < nums.size() - 1; j++) {
            int i = j - 1, k = j + 1;
            if (uniqueNums.contains(nums[i]) && uniqueNums.contains(nums[j]) && uniqueNums.contains(nums[k]))
                continue;

            uniqueNums.insert(nums[j]);

            while (i >= 0 && k < nums.size()) {
                if (nums[i] < nums[j] && nums[j] < nums[k])
                    return true;
                if (nums[i] >= nums[j])
                    i--;
                if (nums[k] <= nums[j])
                    k++;
            }
        }

        return false;
    }
};