class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lastElement = nums.size() - 1;
        int k = 0;
        while (k <= lastElement) {
            if (nums[k] == val) {
                nums[k] = nums[lastElement];
                nums.pop_back();
                lastElement--;
            } else
                k++;
        }
        return nums.size();
    }
};