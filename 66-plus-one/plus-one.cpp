class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;
        if (digits[last] == 9) {
            while(last >= 0 && digits[last]==9) {
                digits[last] = 0;
                last--;
            }
            if (last == -1) {
                digits.insert(digits.begin(), 1);
            } else {
                digits[last]++;
            }
        } else {
            digits[last]++;
        }
        return digits;
    }
};