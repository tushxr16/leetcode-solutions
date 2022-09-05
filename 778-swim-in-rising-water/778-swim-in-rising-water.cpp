class Solution {
public:
    class Pair{
        public:
            int r;
            int c;
            int v;

            Pair(int row, int col, int val){
                this->r = row;
                this->c = col;
                this->v = val;
            }
    };
    
    class Compare{
        public:
            bool operator()(Pair const &a, Pair const &b){
                return a.v > b.v;
            }
    };
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        
        priority_queue<Pair, vector<Pair>, Compare> pq;
        pq.push(Pair(0,0,grid[0][0]));
        
        while(!pq.empty()){
            
            Pair top = pq.top();
            pq.pop();
            vis[top.r][top.c] = true;
            
            if(top.r == n-1 && top.c == n-1){
                return top.v;
            }
            
            for(int i=0;i<4;i++){
                int nr = top.r + dx[i];
                int nc = top.c + dy[i];
                
                if(nr<0 || nc<0 || nr>=n || nc>=n || vis[nr][nc]){
                    continue;
                }
                
                pq.push(Pair(nr,nc,max(top.v, grid[nr][nc])));
                
            }
        }
        return 0;
    }
};