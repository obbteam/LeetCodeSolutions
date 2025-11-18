class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        for (; i < bits.size() - 1; ++i) i+=bits[i];
        return i == bits.size() - 1;
    }
};