class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto cur = m + n - 1;
        auto p1 = m - 1, p2 = n - 1;

        while (cur >= 0) {
            if (p1 >= 0 && p2>=0 && nums1[p1] >= nums2[p2])
                swap(nums1[cur], nums1[p1--]);
            else if (p2 >= 0)
                swap(nums1[cur], nums2[p2--]);
            cur--;
        }
    }
};