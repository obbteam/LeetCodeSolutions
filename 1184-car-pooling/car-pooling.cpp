class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> v;
        for (auto t : trips) {
            v.push_back({t[1], t[0]});
            v.push_back({t[2], -t[0]});
        }
        sort(v.begin(), v.end());

        for (auto i : v) {
            capacity -= i.second;
            if (capacity < 0) return false; 
        }
        return true;
    }
};