class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int buy = prices[0], sell = prices[1], profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[i - 1]) {
                profit += max(sell - buy, 0);
                sell = 0;
                buy = prices[i];
                continue;
            }
            buy = min(buy, prices[i]);
            sell = max(sell, prices[i]);
        }
        profit += max(sell - buy, 0);
        return profit;
    }
};