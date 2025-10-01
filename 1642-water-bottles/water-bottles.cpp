class Solution {
public:
    int helper(int empty, int numExchange) {
    if (empty < numExchange) return 0;

    return empty / numExchange + helper(empty % numExchange + empty / numExchange, numExchange);
}

int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + helper(numBottles, numExchange);
}
};