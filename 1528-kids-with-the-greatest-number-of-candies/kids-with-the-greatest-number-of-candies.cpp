class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_n = 0;
        for (int i = 0; i < candies.size(); ++i) {
            max_n = std::max(max_n, candies[i]);
        }

        std::vector<bool> result; 
        for (int i = 0; i < candies.size(); ++i) {
            result.emplace_back(candies[i] + extraCandies >= max_n);
        }
        return result;
    }
};