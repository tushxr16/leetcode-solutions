class Solution {
public:
    class Pair{
        public:
            int row;
            int col;
            int msf;

            Pair(int row, int col, int msf){
                this->row = row;
                this->col = col;
                this->msf = msf;
            }
    };
    
    class Compare{
        public:
         bool operator()(Pair const &a, Pair const &b){
            return a.msf > b.msf;
        }
    };
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        
        priority_queue<Pair,vector<Pair>,Compare> pq;
        pq.push(Pair(0,0,grid[0][0]));
        
        vis[0][0] = true;
        
        while(!pq.empty()){
            Pair top = pq.top();
            pq.pop();
            
            if(top.row==n-1 && top.col==n-1){
                return top.msf;
            }
            
            vis[top.row][top.col] = true;
            
            if(top.row+1<n && !vis[top.row+1][top.col])
                pq.push(Pair(top.row+1,top.col,max(top.msf,grid[top.row+1][top.col])));
            if(top.col+1<n && !vis[top.row][top.col+1])
                pq.push(Pair(top.row,top.col+1,max(top.msf,grid[top.row][top.col+1])));
            if(top.row-1>=0 && !vis[top.row-1][top.col])
                pq.push(Pair(top.row-1,top.col,max(top.msf,grid[top.row-1][top.col])));
            if(top.col-1>=0 && !vis[top.row][top.col-1])
                pq.push(Pair(top.row,top.col-1,max(top.msf,grid[top.row][top.col-1])));
            
        }
        
        return 0;
    }
};