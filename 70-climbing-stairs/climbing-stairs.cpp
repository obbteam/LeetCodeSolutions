class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int x2 = 1;
        int x1 = 2;
        int res = x1 + x2;
        for (int i = 3; i <= n; i++) {
            res = x1 + x2;
            x2 = x1;
            x1 = res;
        }
        return res;
    }
};