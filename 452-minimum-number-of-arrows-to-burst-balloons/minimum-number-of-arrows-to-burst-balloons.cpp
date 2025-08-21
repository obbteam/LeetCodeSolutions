class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(),
                  [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        int l = INT_MIN, r = INT_MAX, count = 1;
        for (const auto& interval : points) {
            if (interval[0] <= r && interval[0] >= l) {
                l = max(l, interval[0]);
                r = min(r, interval[1]);
            } else {
                l = interval[0];
                r = interval[1];
                count++;
            }
        }

        return count;
    }
};