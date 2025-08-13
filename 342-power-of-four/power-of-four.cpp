class Solution {
public:
    bool isPowerOfFour(int n) { return n > 0 && !isPowerOfFour(n >> 1) && (n & (n - 1)) == 0; }
};