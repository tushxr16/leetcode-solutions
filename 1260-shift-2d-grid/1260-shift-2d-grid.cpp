class Solution {
public:
    vector<vector<int>> changeByOne(vector<vector<int>>& grid){
        int n=grid[0].size(),m=grid.size();
        vector<vector<int>> grid2(grid.begin(),grid.end());
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==n-1 & i==m-1)grid2[0][0]=grid[i][j];
                else if(j==n-1)grid2[i+1][0]=grid[i][j];
                else grid2[i][j+1]=grid[i][j];
            }
        }
        return grid2;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int t=0;t<k;t++){
            grid = changeByOne(grid);
        }
        return grid;
    }
};