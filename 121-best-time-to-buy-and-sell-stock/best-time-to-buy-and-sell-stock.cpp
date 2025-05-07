class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = -1;
        int prev_min = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prev_min)
                prev_min = prices[i];

            if (prices[i] - std::min(buy, prev_min) >= sell - buy) {
                buy = std::min(prev_min, buy);
                sell = prices[i];
            }
        }

        if (sell - buy < 0)
            return 0;

        return sell - buy;
    }
};