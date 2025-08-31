class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int left = nums[0];
        vector<string> result;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (left == nums[i - 1])
                    result.push_back(to_string(left));
                else
                    result.push_back(to_string(left) + "->" +
                                     to_string(nums[i - 1]));
                left = nums[i];
            }
        }
        if (nums.back() == left)
            result.push_back(to_string(left));
        else
            result.push_back(to_string(left) + "->" + to_string(nums.back()));
        return result;
    }
};