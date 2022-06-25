// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int x, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsvis){
        vis[x] = true;
        dfsvis[x] = true;
        for(int i=0;i<adj[x].size();i++){
            if(!vis[adj[x][i]]){
                if(dfs(adj[x][i],adj,vis,dfsvis))
                    return true;
            }else if(dfsvis[adj[x][i]])
                return true;
        }
        dfsvis[x] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<bool> dfsvis(V,false);
        
        for(int t=0;t<V;t++){
            if(!vis[t])
                if(dfs(t,adj,vis,dfsvis))
                    return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends