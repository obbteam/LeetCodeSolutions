class Solution {
public:
    bool checkSpeed(double speed, int h, vector<int>& piles) {
        int minHours = 0;
        for (auto p : piles) {
            minHours += std::ceil(1.0f * p / speed);
        }
        return minHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = (l + r) / 2;
            if (checkSpeed(mid, h, piles))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};