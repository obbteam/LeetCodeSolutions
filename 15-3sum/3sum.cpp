class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(),nums.end());
        for(int i = 0; i + 2 < nums.size(); i++) {
            if(i !=0 && nums[i-1]==nums[i]) continue;

            auto lo = nums.begin() + (i + 1);
            auto hi = nums.end() - 1;
            while(lo < hi) {
                if(*lo + *hi == -nums[i]) {
                    std::vector<int> temp = {nums[i],*lo,*hi};
                    if(!std::binary_search(result.begin(),result.end(),temp)) {
                        result.push_back(temp);
                    } 
                    lo++;
                    hi--;
                } else {
                    if(*lo + *hi + nums[i] < 0) lo++;
                    if(*lo + *hi + nums[i] > 0) hi--;
                }
            }
        }
        return result;
    }
};