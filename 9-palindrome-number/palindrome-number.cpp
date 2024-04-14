class Solution {
public:
    bool isPalindrome(int x) {
        int buff = x;
        if (buff < 0)
            return false;

        long reversed = 0;
        while (buff != 0) {
            int digit = buff % 10;
            reversed = reversed * 10 + digit;
            buff = (buff - digit) / 10;
        }

        if (reversed == x)
            return true;
        return false;
    }
};