//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int x, int y, int &n, int &m, vector<vector<int>> &grid, string &str, int &i, int &j){
        if(x>=n || x<0 || y>=m || y<0 || grid[x][y]==0){
            return;
        }
        str.push_back('0'+x-i);
        str.push_back('0'+y-j);
        grid[x][y] = 0;
        dfs(x+1,y,n,m,grid,str,i,j);
        dfs(x-1,y,n,m,grid,str,i,j);
        dfs(x,y+1,n,m,grid,str,i,j);
        dfs(x,y-1,n,m,grid,str,i,j);
        return;
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> st;
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    string str;
                    dfs(i,j,n,m,grid,str,i,j);
                    if(st.find(str)==st.end()){
                        st.insert(str);
                    }
                }
            }
        }
        
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends