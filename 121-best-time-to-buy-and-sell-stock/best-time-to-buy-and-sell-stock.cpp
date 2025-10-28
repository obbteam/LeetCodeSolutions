class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = INT_MAX, profit = 0;
        for (auto r : prices) {
            profit = max(profit, r - l);
            l = min(l, r);
        }
        return profit;
    }
};