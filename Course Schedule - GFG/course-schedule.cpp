//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    bool isCycle(int x, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis, vector<int> &st){
        vis[x] = true;
        pathVis[x] = true;
        
        for(int i: adj[x]){
            if(!vis[i]){
                if(isCycle(i,adj,vis,pathVis,st)){
                    return true;
                }
            }else if(pathVis[i]){
                return true;
            }
        }
        st.push_back(x);
        pathVis[x] = false;
        return false;
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        vector<bool> vis(n,false), pathVis(n,false);
        vector<int> st;
        for(int i=0;i<m;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,adj,vis,pathVis,st)){
                    return {};
                }
            }
        }
        
        return st;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends