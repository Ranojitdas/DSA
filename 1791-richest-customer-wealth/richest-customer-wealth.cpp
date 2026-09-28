class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        
        int maxWealth = 0;
        for(int i=0;i<m;i++){
            int n = accounts[i].size();
            int wealth = 0;
            for(int j=0;j<n;j++){
                wealth = wealth + accounts[i][j];
            }
            maxWealth = max(maxWealth,wealth);
        }
        return maxWealth;
    }
};