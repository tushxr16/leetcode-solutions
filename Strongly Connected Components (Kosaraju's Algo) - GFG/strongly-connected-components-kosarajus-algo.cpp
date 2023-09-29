//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int x, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st){
	    vis[x] = true;
	    
	    for(int i: adj[x]){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    
	    st.push(x);
	}
	
	void dfsT(int x, vector<bool> &vis, vector<vector<int>> &adjT){
	    vis[x] = true;
	    
	    for(int i: adjT[x]){
	        if(!vis[i]){
	            dfsT(i,vis,adjT);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //Topological sort
        stack<int> st;
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        // Transpose
        vector<vector<int>> adjT(V);
        
        for(int i=0;i<V;i++){
            vis[i] = false;
            for(int x: adj[i]){
                adjT[x].push_back(i);
            }
        }
        
        int cnt = 0;
        
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(!vis[x]){
                dfsT(x,vis,adjT);
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends