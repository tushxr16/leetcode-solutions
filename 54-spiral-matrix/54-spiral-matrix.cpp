class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int r = matrix.size(), c = matrix[0].size(), lc = 0, lr = 0;
        int cnt = r*c;
        while(cnt){
            if(cnt<=0){
                break;
            }
            for(int i=lc;i<c;i++){
                ans.push_back(matrix[lr][i]);
                cnt--;
            }
            if(cnt<=0){
                break;
            }
            lr++;
            for(int i=lr;i<r;i++){
                ans.push_back(matrix[i][c-1]);
                cnt--;
            }
            if(cnt<=0){
                break;
            }
            c--;
            for(int i=c-1;i>=lc;i--){
                ans.push_back(matrix[r-1][i]);
                cnt--;
            }
            if(cnt<=0){
                break;
            }
            r--;
            for(int i=r-1;i>=lr;i--){
                ans.push_back(matrix[i][lc]);
                cnt--;
            }
            lc++;
        }
        return ans;
    }
};