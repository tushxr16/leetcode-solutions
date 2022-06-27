// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        queue<pair<int,int>> q;
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(grid[i][j]==2)
                    q.push({i,j});
        }
        
        while(!q.empty()){
            int q_n = q.size();
            
            for(int i=0;i<q_n;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>0 && grid[x-1][y]==1){
                    q.push({x-1,y});
                    grid[x-1][y] = 2;
                }
                if(y>0 && grid[x][y-1]==1){
                    q.push({x,y-1});
                    grid[x][y-1] = 2;
                }
                if(x<n-1 && grid[x+1][y]==1){
                    q.push({x+1,y});
                    grid[x+1][y] = 2;
                }
                if(y<m-1 && grid[x][y+1]==1){
                    q.push({x,y+1});
                    grid[x][y+1] = 2;
                }
            }
            if(q.size())
                ans++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends