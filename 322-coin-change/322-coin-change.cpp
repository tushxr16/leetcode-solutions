class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e6));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(j==0){
                    dp[i][j] = 0;
                }
                else if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        if(dp[n][amount]==1e6){
            return -1;
        }
        return dp[n][amount];
    }
};