//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int> > > q;
        int ans = 0, oranges = 0, n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2)
                    q.push({0,{i,j}});
                else if(grid[i][j]==1)
                    oranges++;
                    
        while(!q.empty()){
            int timeSpent = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            ans = max(ans, timeSpent);
            
            int dx[4] = {0,1,0,-1};
            int dy[4] = {1,0,-1,0};
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<n && nx>-1 && ny<m && ny>=-1 && grid[nx][ny]==1){
                    oranges--;
                    grid[nx][ny] = 2;
                    q.push({timeSpent+1,{nx,ny}});
                }
            }
            
        }
        if(oranges!=0)
            return -1;
        else
            return ans;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends