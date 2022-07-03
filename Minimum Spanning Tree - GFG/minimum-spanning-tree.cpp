// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> weights(V,INT_MAX);
        vector<bool> setMST(V,false);
        weights[0] = 0;
        for(int i=0;i<V-1;i++){
            
            int mini = INT_MAX, u;
            
            for(int v=0;v<V;v++){
                if(mini>weights[v] && setMST[v]==false){
                    mini = weights[v];
                    u = v;
                }
            }
            
            setMST[u] = true;
            
            for(auto x: adj[u]){
                if(setMST[x[0]]==false && x[1]<weights[x[0]]){
                    weights[x[0]] = x[1];
                }
            }
        }
        
        int sum = 0;
        for(int i=0;i<V;i++)
            sum+=(weights[i]);
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends