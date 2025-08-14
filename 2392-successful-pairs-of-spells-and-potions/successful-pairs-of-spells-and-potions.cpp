class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
    std::sort(potions.begin(), potions.end());

    for (auto &spell: spells) {
        int lo = 0, hi = potions.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            double div = potions[mid] / (double)success;
            if (spell * div < 1)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        spell = potions.size() - lo;
    }

    return spells;
}
};