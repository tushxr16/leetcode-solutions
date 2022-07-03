// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int findMinIndex(vector<int> &weights, vector<bool> &visited, int V){
        int idx, minimum_value = INT_MAX;
        
        for(int i=0;i<V;i++){
            if(weights[i]<minimum_value && !visited[i]){
                minimum_value = weights[i];
                idx = i;
            }
        }
        
        return idx;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> weights(V,INT_MAX);
        vector<bool> visited(V,false);
        weights[S] = 0;
        
        for(int i=0;i<V-1;i++){
            
            int min_index = findMinIndex(weights,visited,V);
            visited[min_index] = true;
            
            for(auto curr_node: adj[min_index]){
                int node_val = curr_node[0];
                int weight = curr_node[1];
                if(!visited[node_val]){
                    weights[node_val] = min(weights[node_val],weights[min_index] + weight);
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