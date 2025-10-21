class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> first;
        for (auto x : nums1) {
            first[x]++;
        }

        for (auto x : nums2) {
            if (first.contains(x) && first[x] > 0) {
                res.emplace_back(x);
                first[x]--;
            }
        }
        return res;
    }
};