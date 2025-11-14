class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b ){
            return a[0] < b[0];
        });
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            auto &cur = ans.back();
            if (cur[1] >= intervals[i][0]) {
                int end = max(intervals[i][1], cur[1]);
                cur[1] = end;
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};