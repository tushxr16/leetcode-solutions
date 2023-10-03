//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                q.push({i,0});
            }
            vis[i][0] = true;
            if(mat[i][m-1]=='O'){
                q.push({i,m-1});
            }
            vis[i][m-1] = true;
        }
        
        for(int i=1;i<m-1;i++){
            if(mat[0][i]=='O'){
                q.push({0,i});
            }
            vis[0][i] = true;
            if(mat[n-1][i]=='O'){
                q.push({n-1,i});
            }
            vis[n-1][i] = true;
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
                
                if(nx>-1 && nx<n && ny>-1 && ny<m && !vis[nx][ny] && mat[nx][ny]=='O'){
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends