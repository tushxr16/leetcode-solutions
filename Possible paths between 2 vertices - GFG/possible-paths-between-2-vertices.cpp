// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int count = 0;
    void dfs(int x, vector<int> adj[], vector<bool> &vis, int dest){
        if(x==dest){
            count++;
            return;
        }
        if(vis[x]){
            return;
        }
        vis[x] = true;
        for(int j=0;j<adj[x].size();j++){
            if(!vis[adj[x][j]]){
                dfs(adj[x][j],adj,vis,dest);
            }
        }
        vis[x] = false;
        return;
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<bool> vis(V,false);
        dfs(source,adj,vis,destination);
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends