//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ans = 0, n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    
                    q.push({i,j});
                    grid[i][j] = 0;
                    int res = 0;
                    
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        res++;
                        
                        int dx[8] = {-1,0,1};
                        int dy[8] = {-1,0,1};
                        
                        for(int X=0;X<3;X++){
                            for(int Y=0;Y<3;Y++){
                                int nx = x + dx[X];
                                int ny = y + dy[Y];
                                
                                if(nx<n && nx>-1 && ny<m && ny>-1 && grid[nx][ny]==1){
                                    q.push({nx,ny});
                                    grid[nx][ny] = 0;
                                }
                            }
                        }
                    }
                    
                    ans = max(ans, res);
                }
            }
        }
        
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends