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
        while (left->second < right->second) {
            if (abs(left->second) == right->second) {
                return right->second;
            } else {
                if (abs(left->second) < right->second) {
                    right--;
                } else if (abs(left->second) > right->second) {
                    left++;
                }
            }
        }

        return -1;
    }
};