// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isBipartiteUtil(vector<int> adj[], vector<int> &color, int V, int x){
        queue<int> q;
        q.push(x);
        color[x] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x:adj[curr]){
                if(color[x]==color[curr])
                    return false;
                if(color[x]==-1){
                    color[x] = 1 - color[curr];
                    q.push(x);
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1)
	            if(!isBipartiteUtil(adj,color,V,i))
	                return false;
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends