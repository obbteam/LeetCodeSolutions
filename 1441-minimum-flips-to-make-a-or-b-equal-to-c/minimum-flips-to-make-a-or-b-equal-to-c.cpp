class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a > 0 || b > 0 || c > 0) {
            auto bitA = a & 1;
            auto bitB = b & 1;
            auto bitC = c & 1;

            if (bitC == 0) {
                flips += bitA + bitB;
            } else if (bitC == 1 && bitA == 0 && bitB == 0)
                flips++;

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};