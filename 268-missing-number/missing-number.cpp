class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i <= n; ++i) {
            sum+=i;
        }

        for (auto x : nums) {
            sum -= x;
        }
        
        return sum;
    }
};