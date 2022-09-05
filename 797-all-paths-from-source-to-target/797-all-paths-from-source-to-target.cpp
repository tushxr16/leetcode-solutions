class Solution {
public:
    void dfs(int x, vector<vector<int>> &adj, vector<int> curr, vector<vector<int>> &ans, int &V){
        if(x==V-1){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<adj[x].size();i++){
            curr.push_back(adj[x][i]);
            dfs(adj[x][i],adj,curr,ans,V);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> ans;
        vector<vector<int>> adj(V);
        vector<int> curr;
        curr.push_back(0);
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        dfs(0,adj,curr,ans,V);
        return ans;
    }
};