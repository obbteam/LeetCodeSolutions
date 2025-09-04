class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hm;
        for (int n : nums)
            hm[n]++;
        
        int major = nums[0], count = 1;
        for (auto [first, second] : hm){
            if (second > count) {
                count = second;
                major = first;
            }
        }
        return major;
    }
};