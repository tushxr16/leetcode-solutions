// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class prio{
    public:
    bool operator()(pair<int,pair<int,int>> &p1, pair<int, pair<int,int>> &p2){
        return p1.second.second > p2.second.second;
    }
};

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> vis(501,vector<bool>(501,false));
        vector<vector<int>> dis(501,vector<int>(501,1e8)); 
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, prio> pq;
        dis[0][0] = grid[0][0];
        pq.push({0,{0,grid[0][0]}});
        
        while(!pq.empty()){
            pair<int,pair<int,int>> tp = pq.top();
            pq.pop();
            int x = tp.first, y = tp.second.first, val = tp.second.second;
            
            if(vis[x][y])
                continue;
                
            if(x+1<n){
                if(dis[x+1][y]>dis[x][y]+grid[x+1][y]){
                    dis[x+1][y] = dis[x][y]+grid[x+1][y];
                    pq.push({x+1,{y, dis[x+1][y]}});
                }
            }
            if(x-1>=0){
                if(dis[x-1][y]>dis[x][y]+grid[x-1][y]){
                    dis[x-1][y] = dis[x][y]+grid[x-1][y];
                    pq.push({x-1,{y, dis[x-1][y]}});
                }
            }
            if(y+1<m){
                if(dis[x][y+1]>dis[x][y]+grid[x][y+1]){
                    dis[x][y+1] = dis[x][y]+grid[x][y+1];
                    pq.push({x,{y+1, dis[x][y+1]}});
                }
            }
            if(y-1>=0){
                if(dis[x][y-1]>dis[x][y]+grid[x][y-1]){
                    dis[x][y-1] = dis[x][y]+grid[x][y-1];
                    pq.push({x,{y-1, dis[x][y-1]}});
                }
            }
        }
        
        return dis[n-1][m-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends