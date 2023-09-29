//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int src, int &c, int &d, vector<int> adj[], vector<bool> &vis){
        vis[src] = true;
        
        for(int i: adj[src]){
            if((i==c && src==d) || (i==d && src==c)){
                continue;
            }
            if(!vis[i]){
                dfs(i,c,d,adj,vis);
            }
        }
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(c,c,d,adj,vis);
            }
        }
        
        return !vis[d];
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends