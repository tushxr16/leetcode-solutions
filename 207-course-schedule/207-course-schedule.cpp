class Solution {
public:
    bool dfs(int x, vector<bool> &dfsvis, vector<bool> &vis, vector<vector<int>> &adj){
        vis[x] = true;
        dfsvis[x] = true;
        for(auto j: adj[x]){
            if(!vis[j]){
                if(dfs(j,dfsvis,vis,adj)){
                    return true;
                }
            }else if(dfsvis[j]){
                return true;
            }
        }
        dfsvis[x] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(V);
        
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> vis(V,false);
        vector<bool> dfsvis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,dfsvis,vis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};