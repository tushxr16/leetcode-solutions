class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &adj,vector<vector<int>> &dp){
        int n = adj.size(), m = adj[0].size();
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(adj[i][j]==1){
            return dp[i][j] = 0;
        }
        return dp[i][j] = dfs(i+1,j,adj,dp) + dfs(i,j+1,adj,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1){
            return 0;
        }
        vector<vector<int>> dp(101,vector<int>(101,-1));
        return dfs(0,0,obstacleGrid,dp);
    }
};