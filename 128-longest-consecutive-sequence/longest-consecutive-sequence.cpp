class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> distinct(nums.begin(), nums.end());

        int longest = 0;
        for (int i : distinct) {
            if (!distinct.count(i-1)) {
                int cur = 0;
                while(distinct.count(i)) {
                    cur++;
                    i++;
                }

                longest = max(cur, longest);
            }
        }
        return longest;
    }
};