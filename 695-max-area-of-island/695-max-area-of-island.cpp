class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1}; 
    void dfs(int i,int j,int n ,int m,vector<vector<int>>& grid,int &t)
    {
        if(i<0|| j<0 || i>=n || j>=m || grid[i][j] == 0) return;
        grid[i][j] = 0;
        t++;
        for(int k = 0;k<4;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            dfs(x,y,n,m,grid,t);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visi(r,vector<int>(c,0));
        int count = 0;
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                if(grid[i][j]==1){
                    int temp = 0;
                    dfs(i,j,r,c,grid,temp);
                    count = max(count,temp);
                }
            }
        }
        
        return count;
        
    }
};