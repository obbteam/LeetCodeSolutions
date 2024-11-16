class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                auto found = std::binary_search(nums.begin() + j + 1, nums.end(),  - nums[i] - nums[j] );
                if(found)  {
                    std::vector<int> temp = {nums[i],nums[j], - nums[i] - nums[j]};
                    auto found_result = std::binary_search(result.begin(), result.end(),temp);
                    if(!found_result) result.push_back(temp);
                }
            }
        }
        return result;
    }
};