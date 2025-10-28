class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int leftSum = 0, ans = 0, rightSum = 0;
        for (auto x : nums) rightSum+=x;

        for (auto x : nums) {
            if (x == 0) {
                if (leftSum == rightSum || leftSum - rightSum == 1)
                    ans++;
                if (leftSum == rightSum || rightSum - leftSum == 1)
                    ans++;
            } else {
                leftSum += x;
                rightSum -=x;
            }
        }
        
        return ans;
    }
};