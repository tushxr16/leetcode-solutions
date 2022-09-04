class Solution {
public:
    bool dfs(int x, vector<bool> &vis, vector<bool> &dfsvis, vector<vector<int>> &graph){
        vis[x] = true;
        dfsvis[x] = true;
        for(auto k: graph[x]){
            if(!vis[k]){
                if(dfs(k,vis,dfsvis,graph)){
                    return true;
                }
            }else if(dfsvis[k]){
                return true;
            }
        }
        dfsvis[x] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<bool> vis(V,false);
        vector<bool> dfsvis(V,false);
        vector<vector<int>> graph(V);
        for(auto edge: prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,dfsvis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};