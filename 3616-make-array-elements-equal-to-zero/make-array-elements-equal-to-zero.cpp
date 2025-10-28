class Solution {
public:
    vector<int> dirs = {1, -1};

    int helper(int i, int nonZeros, vector<int>& nums) {
        int count = 0;

        for (auto d : dirs) {
            auto cp = nums;
            int nz = nonZeros;
            int cur = i;
            while (nz > 0 && cur >= 0 && cur < nums.size()) {
                if (cp[cur] > 0) {
                    cp[cur]--;

                    if (cp[cur] == 0)
                        nz--;
                    d *= -1;
                }
                cur += d;
            }

            if (nz == 0)
                count++;
        }

        return count;
    }

    int countValidSelections(vector<int>& nums) {
        int count = 0, nonZeros = 0;

        for (auto x : nums) {
            if (x > 0) {
                nonZeros++;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                count += helper(i, nonZeros, nums);
        }
        return count;
    }
};