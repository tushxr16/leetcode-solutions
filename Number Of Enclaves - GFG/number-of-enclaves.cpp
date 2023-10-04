//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                grid[i][0] = 0;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                grid[i][m-1] = 0;
                q.push({i,m-1});
            }
        }
        for(int i=1;i<m-1;i++){
            if(grid[0][i]==1){
                grid[0][i] = 0;
                q.push({0,i});
            }
            if(grid[n-1][i]==1){
                grid[n-1][i] = 0;
                q.push({n-1,i});
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int dx[4] = {0,1,0,-1};
            int dy[4] = {1,0,-1,0};
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<n && nx>-1 && ny<m && ny>-1 && grid[nx][ny]==1){
                    grid[nx][ny] = 0;
                    q.push({nx,ny});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends