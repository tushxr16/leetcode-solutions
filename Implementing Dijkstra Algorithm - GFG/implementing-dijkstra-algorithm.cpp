// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int getMinimumWeight(vector<int> &weights, vector<bool> &vis, int V){
        int mn=INT_MAX, idx = 0;
        for(int i=0;i<V;i++){
            if(!vis[i] && mn>weights[i]){
                idx = i;
                mn = weights[i];
            }
        }
        return idx;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> weights(V,INT_MAX);
        vector<bool> vis(V,false);
        weights[S] = 0;
        
        for(int i=0;i<V-1;i++){
            
            int x = getMinimumWeight(weights,vis,V);
            vis[x] = true;
            
            for(auto node: adj[x]){
                int node_val = node[0];
                int weight = node[1];
                if(!vis[node_val] && weights[node_val]>weight+weights[x]){
                    weights[node_val] = weight + weights[x];
                }
            }
        }
        
        return weights;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends