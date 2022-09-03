class Solution {
public:
    void dfs(int x, vector<bool> &vis, vector<vector<int>> &graph){
        vis[x] = true;
        for(auto k: graph[x]){
            if(!vis[k]){
                dfs(k,vis,graph);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1){
            return -1;
        }
        
        vector<bool> vis(n,false);
        vector<vector<int>> graph(n);
        
        for(auto edge: connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int not_connected = 0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                not_connected++;
                dfs(i,vis,graph);
            }
        }
        
        return not_connected-1;
    }
};