class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool can = false;

        int* r = &nums.back();
        int* l = r--;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] >= r - l) {
                can = true;
                r = l;
            } else
                can = false;
            l--;
        }
        return can;
    };
};