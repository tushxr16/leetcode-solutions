// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void markIsland(vector<vector<char>> &mat, int i, int j, int rows, int cols){
        if(i<0 || i>=rows || j<0 || j>=cols || mat[i][j]!='1')
            return ;
        mat[i][j] = '0';
        markIsland(mat,i+1,j,rows,cols);
        markIsland(mat,i,j+1,rows,cols);
        markIsland(mat,i-1,j,rows,cols);
        markIsland(mat,i,j-1,rows,cols);
        markIsland(mat,i+1,j+1,rows,cols);
        markIsland(mat,i+1,j-1,rows,cols);
        markIsland(mat,i-1,j+1,rows,cols);
        markIsland(mat,i-1,j-1,rows,cols);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0)
            return 0;
        int cols = grid[0].size();
        
        int island = 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    markIsland(grid,i,j,rows,cols);
                    island++;}
            }
        }
        
        return island;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends