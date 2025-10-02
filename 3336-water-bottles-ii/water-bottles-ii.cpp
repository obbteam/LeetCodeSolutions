class Solution {
public:
    int helper(int empty, int num) {
        if (empty < num) return 0;

        int full = 0;
        while (empty >= num) {
            empty-=num;
            full++;
            num++;
        }

        return full + helper(full + empty, num);
    }

    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles + helper(numBottles, numExchange);
    }
};