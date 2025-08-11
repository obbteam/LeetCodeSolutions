class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        std::unordered_set<int> visited;
        int provinces = 0;

        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited.contains(i)){
                dfs(i, visited, isConnected);
                provinces++;
            }
        }

        return provinces;
    }

    void dfs(int city, std::unordered_set<int> &visited, vector<vector<int>>& isConnected) {
        visited.insert(city);
        for (int i = 0; i < isConnected[city].size(); ++i) {
            if (isConnected[city][i] == 1 && !visited.contains(i)) 
                dfs(i, visited, isConnected);
        }
    }
};