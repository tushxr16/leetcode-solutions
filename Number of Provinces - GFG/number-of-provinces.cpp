// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int x, vector<vector<int>> &adj, vector<bool> &vis){
        vis[x] = true;
        
        for(int j=0;j<adj[x].size();j++){
            if(!vis[j] && adj[x][j]){
                vis[j] = true;
                dfs(j,adj,vis);
            }
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> vis(V,false);
        int provinces = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                provinces++;
                dfs(i,adj,vis);
            }
        }
        return provinces;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends