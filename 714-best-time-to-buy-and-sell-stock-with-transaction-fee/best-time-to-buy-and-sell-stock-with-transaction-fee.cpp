class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0]; // max cash if holding a stock
        int cash = 0;          // max cash if not holding

        for (int i = 1; i < n; ++i) {
            hold = max(hold, cash - prices[i]); // buy OR keep holding
            cash = max(cash, hold + prices[i] -
                                 fee); // sell and pay the fee OR keep cash
        }
        return cash;
    }
};