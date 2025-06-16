class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h_altitude = 0;
        int path = 0;
        for (int i = 0; i < gain.size(); i++) {
            path += gain[i];
            h_altitude = std::max(h_altitude, path);
        }
        return h_altitude;
    }
};