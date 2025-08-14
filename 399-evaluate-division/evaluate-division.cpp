class Solution {
public:
    using Graph =
        std::unordered_map<std::string,
                           std::vector<std::pair<std::string, double>>>;

    double dfs(Graph& map, const std::string& src, const std::string& dst,
               std::unordered_set<std::string>& seen) {
        if (!map.contains(src))
            return -1.0f;
        if (src == dst)
            return 1.0f;

        seen.insert(src);
        for (auto [nbr, val] : map[src]) {
            if (seen.contains(nbr))
                continue;

            auto res = dfs(map, nbr, dst, seen);
            if (res != -1.0) {
                return val * res; // accumulate product along the path
            }
        }
        return -1.0f;
    }

    std::vector<double>
    calcEquation(std::vector<std::vector<std::string>>& equations,
                 std::vector<double>& values,
                 std::vector<std::vector<std::string>>& queries) {
        Graph equationMap;

        for (int i = 0; i < equations.size(); i++) {
            equationMap[equations[i][0]].emplace_back(
                std::make_pair(equations[i][1], values[i]));
            equationMap[equations[i][1]].emplace_back(
                std::make_pair(equations[i][0], 1 / values[i]));
        }

        std::vector<double> ans;
        ans.reserve(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            const auto& x = queries[i][0];
            const auto& y = queries[i][1];
            if (!equationMap.contains(x) || !equationMap.contains(y)) {
                ans.push_back(-1.0);
                continue;
            }
            std::unordered_set<std::string> seen;
            ans.push_back(dfs(equationMap, x, y, seen));
        }

        return ans;
    }
};