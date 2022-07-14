// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoSortUtil(int x, vector<int> adj[], vector<int> &ans, vector<bool> &vis){
	    
	    vis[x] = true;
	    
	    for(auto j: adj[x]){
	        if(!vis[j])
	            topoSortUtil(j,adj,ans,vis);
	    }
	    
	    ans.push_back(x);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V,false);
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	            topoSortUtil(i, adj, ans, vis);
	    }
	    for(int i=0;i<V/2;i++)
	        swap(ans[i],ans[V-i-1]);
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends