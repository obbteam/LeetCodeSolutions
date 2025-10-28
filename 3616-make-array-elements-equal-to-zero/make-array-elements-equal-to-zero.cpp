class Solution {
public:
    vector<int> dirs = {1, -1};

    int helper(int i, vector<int>& nums) {
        int count = 0;

        for (auto d : dirs) {
            auto cp = nums;
            unordered_set<int> zeros;
            zeros.insert(i);

            // left
            int cur = i;
            while (zeros.size() < cp.size()) {
                cur += d;
                if (cur < 0 || cur >= cp.size())
                    break;

                if (cp[cur] == 0) {
                    if (!zeros.contains(cur))
                        zeros.insert(cur);
                    continue;
                }
                cp[cur]--;

                if (cp[cur] == 0)
                    zeros.insert(cur);
                d = d == -1 ? 1 : -1;
            }
            if (zeros.size() == cp.size())
                count++;
            else {
                int z = 0;
                for (auto x : cp) if (x == 0) z++;
                if (z == cp.size()) count++;
            }
        }

        return count;
    }

    int countValidSelections(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                count += helper(i, nums);
        }
        return count;
    }
};