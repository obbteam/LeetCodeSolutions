class Solution {
public:
    int climbStairs(int n) {
        int solutions[46] = {1, 1};
        for (int k = 2; k <= n; k++) {
            solutions[k] = solutions[k - 1] + solutions[k - 2];
        }
        return solutions[n];
    }
};