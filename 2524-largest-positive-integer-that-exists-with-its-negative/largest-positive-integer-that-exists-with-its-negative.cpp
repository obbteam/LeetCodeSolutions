class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int, int> omap;
        for (int num : nums) {
            omap[num] = num;
        }

        auto left = omap.begin();
        auto right = omap.end();
        right--;
        while (left->second < 0) {
            if (left->second == -1 * right->second) {
                return right->second;
            } else {
                if (left->second * -1 < right->second) {
                    right--;
                } else if (left->second * -1 > right->second) {
                    left++;
                }
            }
        }

        return -1;
    }
};