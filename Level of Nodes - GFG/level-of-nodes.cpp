//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int,int>> q;
	    vector<int> vis(V,false);
	    q.push({0,0});
	    if(X==0){
	        return 0;
	    }
	    while(!q.empty()){
	        pair<int,int> x = q.front();
	        q.pop();
	        vis[x.first] = true;
	        for(int c: adj[x.first]){
	            if(!vis[c])
    	            q.push({c,x.second+1});
	            if(c==X){
	                return x.second+1;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends