class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maximumWealth = 0;
        int currentWealth = 0;

        for(int i=0;i<accounts.size();i++) {
            for(int k =0; k<accounts[i].size();k++) {
                currentWealth += accounts[i][k];
            }
            if(currentWealth>=maximumWealth) maximumWealth = currentWealth;
            currentWealth  = 0;
        }
        return maximumWealth;
    }
};