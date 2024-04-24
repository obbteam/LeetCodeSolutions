class Solution {
public:
    int fib(int n) {
        int Fibonacci[31] = {0,1};
        for(int k = 2; k<=n; k++) {
            Fibonacci[k] = Fibonacci[k-1] + Fibonacci[k-2];
        }
        return Fibonacci[n];
    }
};