class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> umap;
        int result = -1;
        for (int num : nums) {
            int abs_num = abs(num);
            if(abs_num > result && umap.contains(-num)){
                result = abs_num;
            }
            umap.insert(num);
        }
        return result;
    }
};