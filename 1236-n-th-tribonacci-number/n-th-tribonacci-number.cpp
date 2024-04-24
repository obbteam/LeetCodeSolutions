class Solution {
public:
    int tribonacci(int n) {
        int MyArray[38] = {0, 1, 1};
        for (int k = 3; k <= n; k++) {
            MyArray[k] = MyArray[k - 1] + MyArray[k - 2] + MyArray[k - 3];
        }
        return MyArray[n];
    }
};