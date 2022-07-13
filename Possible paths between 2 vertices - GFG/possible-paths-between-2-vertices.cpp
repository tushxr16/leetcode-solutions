// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        queue<int> q;
        int count = 0;
        q.push(source);
        
        if(source==destination)
            return 1;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i=0;i<adj[top].size();i++){
                if(adj[top][i] == destination){
                    count++;
                }
                q.push(adj[top][i]);
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends