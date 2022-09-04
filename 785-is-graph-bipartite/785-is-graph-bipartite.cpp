class Solution {
public:
    bool check(int x, vector<vector<int>> &graph, vector<int> &color){
        queue<int> q;
        q.push(x);
        color[x] = 1;
        while(!q.empty()){
            int n = q.size();
            int curr = q.front();
            q.pop();
            for(auto x: graph[curr]){
                if(color[x]==-1){
                    color[x] = 1-color[curr];
                    q.push(x);
                }else if(color[x]==color[curr]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!check(i,graph,color)){
                    return false;
                }
            }
        }
        
        return true;
    }
};