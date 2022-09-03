class Solution {
public:
    bool dfs(int x, int d, vector<vector<int>> &graph, vector<bool> &vis){
        vis[x] = true;
        for(int i=0;i<graph[x].size();i++){
            if(!vis[graph[x][i]]){
                if(dfs(graph[x][i],d,graph,vis)) return true;
            }
        }
        if(vis[d]) return true;
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n,false);
        vector<vector<int>> graph(n);
        for(auto x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        return dfs(source,destination,graph,vis);
    }
};