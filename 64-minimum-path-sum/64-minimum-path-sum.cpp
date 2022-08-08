class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i<0 || j<0)
            return 1e9;
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = grid[i][j] + helper(i,j-1,dp,grid);
        int right = grid[i][j] + helper(i-1,j,dp,grid);
        return dp[i][j] = min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,dp,grid);
    }
};