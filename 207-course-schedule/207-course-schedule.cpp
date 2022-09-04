class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        
        vector<int> indeg(V,0);
        vector<vector<int>> graph(V);
        queue<int> q;
        int cnt = 1;
        
        for(auto edge: prerequisites){
            graph[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }
        
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            
            for(auto x: graph[i]){
                if(--indeg[x]==0){
                    q.push(x);
                    cnt++;
                }
            }
        }
        for(auto x: indeg){
            if(x!=0){
                return false;
            }
        }
        return true;
    }
};