#include <unordered_map>

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoIndices;
        for(int i = 0; i < nums.size(); i++) {
            for(int k = i+1; k < nums.size(); k++) {
            if(nums[i]+nums[k]==target) {
                    twoIndices.push_back(i);
                    twoIndices.push_back(k);
                }
            }
        }
        return twoIndices;
    }
};