//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        queue<int> q;
        vector<int> bfs;
        
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0;i<n;i++){
                int x = q.front();
                q.pop();
                bfs.push_back(x);
                
                for(int t: adj[x]){
                    if(!vis[t]){
                        q.push(t);
                        vis[t] = true;
                    }
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends