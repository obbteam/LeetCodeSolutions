class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set set1(nums1.begin(), nums1.end());
        std::unordered_set set2(nums2.begin(), nums2.end());

        std::vector<int> distinct1, distinct2;
        for (auto& x : set1) {
            if (!set2.contains(x)) {
                distinct1.push_back(x);
            }
        }
        for (auto& x : set2) {
            if (!set1.contains(x)) {
                distinct2.push_back(x);
            }
        }

        return {distinct1, distinct2};
    }
};