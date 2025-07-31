class Solution {
public:
    int equalPairs(std::vector<std::vector<int> > &grid) {
    std::map<std::vector<int>, int> mp;

    for (auto &row: grid) {
        mp[row]++;
    }

    int ans = 0;

    for (int i = 0; i < grid.size(); i++) {
        std::vector<int> temp;
        for (int j = 0; j < grid[0].size(); j++) {
            temp.push_back(grid[j][i]);
        }
        if (mp.contains(temp)) {
            ans += mp[temp];
        }
    }

    return ans;
}
};