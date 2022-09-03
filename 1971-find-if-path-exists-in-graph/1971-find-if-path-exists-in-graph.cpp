class Solution {
public:
    void dfs(int x, vector<vector<int>> &graph, vector<bool> &vis){
        vis[x] = true;
        for(int i=0;i<graph[x].size();i++){
            if(!vis[graph[x][i]]){
                dfs(graph[x][i],graph,vis);
            }
        }
        return;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n,false);
        vector<vector<int>> graph(n);
        for(auto x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        dfs(source,graph,vis);
        return vis[destination];
    }
};