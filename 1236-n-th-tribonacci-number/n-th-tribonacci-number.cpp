class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;

        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;
        int res = 0;

        for (int i = 3; i <= n; i++) {
            res = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};