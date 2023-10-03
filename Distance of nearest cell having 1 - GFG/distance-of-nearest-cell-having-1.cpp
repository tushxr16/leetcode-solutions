//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,-1));
	    queue<pair<int,pair<int,int>>> q;
	    
	    for(int i=0;i<n;i++)
	        for(int j=0;j<m;j++)
	            if(grid[i][j]==1){
	                q.push({1,{i,j}});
	                vis[i][j] = 0;
	            }
	    
	    while(!q.empty()){
	        int dist = q.front().first;
	        int x = q.front().second.first;
	        int y = q.front().second.second;
	        q.pop();
	        
	        int dx[4] = {1,0,-1,0};
	        int dy[4] = {0,1,0,-1};
	        
	        for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<n && nx>-1 && ny<m && ny>-1 && vis[nx][ny]==-1){
                    q.push({dist + abs(nx-x)+abs(ny-y),{nx,ny}});
                    vis[nx][ny] = dist;
                }
	        }
	    }
	    
	    return vis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends