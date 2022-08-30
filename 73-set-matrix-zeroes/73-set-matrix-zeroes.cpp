class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int,int>> p;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    p.push_back({i,j});
                }
            }
        }
        for(auto x: p){
            int l = x.first;
            int k = x.second;
            for(int i=0;i<n;i++){
                matrix[i][k] = 0;
            }
            for(int i=0;i<m;i++){
                matrix[l][i] = 0;
            }
        }
        return;
    }
};