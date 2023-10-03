//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isEularCircuit(int n, vector<int>adj[]){
	    int ep=0, ec=0;
	    for(int i=0;i<n;i++){
	        int cnt = adj[i].size();
	        if(cnt%2){
	            ep++;
	        }else{
	            ec++;
	        }
	    }
	    if(ep==2){
	        return 1;
	    }else if(ec==n){
	        return 2;
	    }else{
	        return 0;
	    }
	}
};

//{ Driver Code Starts.
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
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends