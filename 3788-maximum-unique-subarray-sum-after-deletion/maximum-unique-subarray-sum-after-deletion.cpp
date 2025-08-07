class Solution {
public:
    int maxSum(vector<int>& nums) {
        std::unordered_set<int> numSet;
        
        int sum = 0, maxElem = INT_MIN;
        for (int num : nums) {
            maxElem = std::max(maxElem, num);
            if (num <=0)
                continue;
            if (numSet.contains(num))
                continue;
            numSet.insert(num);
            sum+=num;
        }

        if (maxElem < 0)
            return maxElem;
        return sum;
    }
};