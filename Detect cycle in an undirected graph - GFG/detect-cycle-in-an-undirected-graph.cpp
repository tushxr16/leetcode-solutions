// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int x, int pp, vector<bool> &vis, vector<int> adj[]){
        vis[x] = true;
        for(auto i: adj[x]){
            if(!vis[i]){
                if(dfs(i,x,vis,adj))
                    return true;
            }else if(i!=pp)
                    return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int j=0;j<V;j++)
            if(!vis[j])
                if(dfs(j,-1,vis,adj))
                    return true;
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends